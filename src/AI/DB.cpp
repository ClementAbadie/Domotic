/*
 * DB.cpp
 *
 *  Created on: 24 juil. 2016
 *      Author: Clément
 */

#include "DB.h"

//MySQL

DB::DB(volatile DBs *myDBs) {
	// TODO Auto-generated constructor stub

	this->myDBs = myDBs;
	this->Connect();
	this->row = 0;

}

DB::DB() {
	// TODO Auto-generated destructor stub
}

DB::~DB() {
	// TODO Auto-generated destructor stub

	//this->Close();
}

int DB::set(int DataType, float value, int room) {

	//if(!TEST){myDBs->realTime[DataType][room] = floor(value * 10 + 0.1) / 10;}

	char query[512];
	sprintf(query, "INSERT INTO measures VALUES ('%d', '%d', '%.1f', '%s');",
			DataType, room, value, dateAndTimeToString().c_str());
	return this->query(query);
}

int DB::setConf(int DataType, float value, int room) {

	myDBs->config[DataType][room] = floor(value * 10 + 0.1) / 10;

	return 0;
}

int DB::setMode(int DataType, int mode, int room) {

	myDBs->mode[DataType][room] = mode;

	return 0;
}

int DB::setUnit(int DataType, string unit, string label, int min, int max) {

	char query[512];

	sprintf(query,
			"INSERT INTO measuresTypes VALUES ('%d', '%s', '%s', '%s', '%d', '%d');",
			DataType, "USELESS", unit.c_str(), label.c_str(), min, max);
	return mysql_query(&mysql, query);

	//myDBs->unit[DataType] = &unit;
}

float DB::get(int DataType, int room) {

	//Requête qui sélectionne tout dans ma table
	char query[512];
	sprintf(query,
			"SELECT * FROM measures WHERE mest = %d AND rooi = %d ORDER BY dat DESC LIMIT 1;",
			DataType, room);
	this->query(query);

	return this->getRowFloat(2);

	//return myDBs->realTime[DataType][room];

}

float DB::getConf(int DataType, int room) {

	return myDBs->config[DataType][room];
}

int DB::getMode(int DataType, int room) {

	return myDBs->mode[DataType][room];
}

string DB::getUnit(int DataType) {

	//Requête qui sélectionne tout dans ma table
	char query[512];
	sprintf(query, "SELECT * FROM measuresTypes WHERE mest = %d;", DataType);
	this->query(query);

	return this->getRowString(2);

	//return 	*myDBs->unit[DataType];
}

string DB::getLabel(string table, string label) {

	//Requête qui sélectionne tout dans ma table
	char query[512];
	sprintf(query, "SELECT * FROM %s;", table.c_str());
	this->query(query);

	MYSQL_RES *result = mysql_store_result(&mysql);
	unsigned int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	unsigned int name_field;
	char *field_name = "label";

	char *headers[num_fields];
	for(unsigned int i = 0; (field = mysql_fetch_field(result)); i++) {
	    headers[i] = field->name;
	    if (strcmp(field_name, headers[i]) == 0) {
	        name_field = i;
	    }
	}

	while ((row = mysql_fetch_row(result))) {
	    //do something with row[name_field]
	    printf("Name: %s\n", row[name_field]);
	}
	return row[name_field];
	mysql_free_result(result);
	//return 	*myDBs->unit[DataType];
}

int DB::Connect() {
	//Initialisation de MySQL
	mysql_init(&mysql);
	//Options de connexion
	mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "MYSQL_READ_DEFAULT_GROUP");

	//Si la connexion réussie...
	if (mysql_real_connect(&mysql, "localhost", "domotic", "domotic", "domotic",
			0, NULL, 0)) {
		cout << "DB : Connected !" << endl;
	} else  //Sinon ...
	{
		cerr << "DB : Error !" << endl;
		cerr << mysql_error(&mysql) << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int DB::Close() {
	//Fermeture de MySQL
	mysql_close(&mysql);
	if (*mysql_error(&mysql)) {
		cerr << mysql_error(&mysql) << endl;
		return EXIT_FAILURE;
	}
	cout << "DB : Closed !" << endl;
	return EXIT_SUCCESS;

}

int DB::TableClear(string table) {
	char query[512];
	sprintf(query, "TRUNCATE TABLE %s", table.c_str());
	if (DEBUG) {
		cout << query << endl;
	}
	mysql_query(&mysql, query);
	if (*mysql_error(&mysql)) {
		cerr << mysql_error(&mysql) << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int DB::TableToConsole(string table) {
	//Requête qui sélectionne tout dans ma table
	char query[512];
	sprintf(query, "SELECT * FROM %s", table.c_str());
	if (DEBUG) {
		cout << query << endl;
	}
	mysql_query(&mysql, query);
	if (*mysql_error(&mysql)) {
		cerr << mysql_error(&mysql) << endl;
		return EXIT_FAILURE;
	}

	//Déclaration des objets

	unsigned int i = 0;
	unsigned int num_champs = 0;

	//On met le jeu de résultat dans le pointeur result
	result = mysql_use_result(&mysql);
	if (result) {
		//On récupère le nombre de champs
		num_champs = mysql_num_fields(result);

		//Tant qu'il y a encore un résultat ...
		while ((row = mysql_fetch_row(result))) {
			//On déclare un pointeur long non signé pour y stocker la taille des valeurs
			unsigned long *lengths;

			//On stocke ces tailles dans le pointeur
			lengths = mysql_fetch_lengths(result);

			//On fait une boucle pour avoir la valeur de chaque champs
			for (i = 0; i < num_champs; i++) {
				//On ecrit toutes les valeurs
				printf("[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");
			}

			cout << endl;
		}
	} else {
		cerr << "Table not found !" << endl;
	}
	//Libération du jeu de résultat
	mysql_free_result(result);

	return 0;

}

int DB::setMeasuresTypesTable() {

	this->TableClear("measuresTypes");

	this->setUnit(val_temperature, "°C", "Température", -50, 100);
	this->setUnit(val_humidity, "%", "Humidité", 0, 100);
	this->setUnit(val_pressure, "mBar", "Pression", 800, 1200);

	return EXIT_SUCCESS;

}

int DB::setActuatorsTypesTable() {
	return this->loadCSVtoTable("actuatorTypes");
}

int DB::loadCSVtoTable(string table) {

	this->TableClear(table);

	char query[512];
	sprintf(query,
			"LOAD DATA LOCAL INFILE '%s%s.csv' INTO TABLE %s FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;",
			CONF_PATH, table.c_str(), table.c_str());

	return this->query(query);

	//myDBs->unit[DataType] = &unit;
}

int DB::query(string query) {

	if (DEBUG) {
		cout << query << endl;
	}

	mysql_query(&mysql, query.c_str());
	if (*mysql_error(&mysql)) {
		cerr << mysql_error(&mysql) << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}

string DB::getRowString(int rowNb) {

	unsigned int num_row = 0;

	//On met le jeu de résultat dans le pointeur result
	result = mysql_store_result(&mysql);
	if (result) {
		//On récupère le nombre de lignes
		num_row = mysql_num_rows(result);

		if (num_row == 1) {
			row = mysql_fetch_row(result);

			std::string svalue(row[rowNb]);

			//Libération du jeu de résultat
			mysql_free_result(result);
			return svalue;
		} else {

			mysql_free_result(result);
			cerr << "Multi-row result !" << endl;
			return "EXIT_FAILURE";
		}
	} else {
		mysql_free_result(result);
		cerr << "Table not found !" << endl;
		return "EXIT_FAILURE";
	}

	//Libération du jeu de résultat
	mysql_free_result(result);
	return "EXIT_FAILURE";

}

float DB::getRowFloat(int rowNb) {

	unsigned int num_row = 0;

	//On met le jeu de résultat dans le pointeur result
	result = mysql_store_result(&mysql);
	if (result) {
		//On récupère le nombre de lignes
		num_row = mysql_num_rows(result);

		if (num_row == 1) {
			row = mysql_fetch_row(result);

			std::string svalue(row[rowNb]);
			float fvalue = ::atof(svalue.c_str());

			//Libération du jeu de résultat
			mysql_free_result(result);
			return fvalue;
		} else {

			mysql_free_result(result);
			cerr << "Multi-row result !" << endl;
			return EXIT_FAILURE;
		}
	} else {
		mysql_free_result(result);
		cerr << "Table not found\n" << endl;
		return EXIT_FAILURE;
	}

	//Libération du jeu de résultat
	mysql_free_result(result);
	return EXIT_FAILURE;

}

int DB::loadConfToTables() {

	int err = 0;
	err += this->loadCSVtoTable("actuatorsTypes");
	err += this->loadCSVtoTable("coms");
	err += this->loadCSVtoTable("rooms");
	err += this->loadCSVtoTable("sensorsConf");
	err += this->loadCSVtoTable("sensorsTypes");
	err += this->loadCSVtoTable("measuresTypes");
	return err;
}


int DB::getRowNumberByName(string rowName) {


	MYSQL_RES *result = mysql_store_result(&mysql);
	unsigned int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	unsigned int name_field;
	char *field_name = "lbl";

	char *headers[num_fields];
	for(unsigned int i = 0; (field = mysql_fetch_field(result)); i++) {
	    headers[i] = field->name;
	    if (strcmp(field_name, headers[i]) == 0) {
	        name_field = i;
	    }
	}

	while ((row = mysql_fetch_row(result))) {
	    //do something with row[name_field]
	    printf("Name: %s\n", row[name_field]);
	}
	return name_field;
	mysql_free_result(result);
	//return 	*myDBs->unit[DataType];
}
