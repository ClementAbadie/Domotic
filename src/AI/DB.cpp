/*
 * DB.cpp
 *
 *  Created on: 24 juil. 2016
 *      Author: Clément
 */


#include "DB.h"

//MySQL

DB::DB(volatile DBs  *myDBs) {
	// TODO Auto-generated constructor stub


	this->myDBs = myDBs;
	this->Connect();


}

DB::DB() {
	// TODO Auto-generated destructor stub
}

DB::~DB() {
	// TODO Auto-generated destructor stub

	//this->Close();
}


int DB::set(int DataType, float value, int room){

	//if(!TEST){myDBs->realTime[DataType][room] = floor(value * 10 + 0.1) / 10;}

	char query[512];
	sprintf(query,"INSERT INTO measures VALUES ('%d', '%d', '%.1f', '%s');",DataType,room,value,dateAndTimeToString().c_str());
	if(DEBUG){cout << query << endl;}
    return mysql_query(&mysql,query);

	return 0;
}

int DB::setConf(int DataType, float value, int room){

	myDBs->config[DataType][room] = floor(value * 10 + 0.1) / 10;

	return 0;
}

int DB::setMode(int DataType, int mode, int room){

	myDBs->mode[DataType][room] = mode;

	return 0;
}



int DB::setUnit(int DataType, string unit, string label, int min, int max)
{

	char query[512];

	sprintf(query,"INSERT INTO measuresTypes VALUES ('%d', '%s', '%s', '%s', '%d', '%d');",DataType,"USELESS",unit.c_str(),label.c_str(),min,max);
	if(DEBUG){cout << query << endl;}
	return mysql_query(&mysql,query);

	//myDBs->unit[DataType] = &unit;
}

float DB::get(int DataType, int room){


	   //Requête qui sélectionne tout dans ma table
		char query[512];
		sprintf(query,"SELECT * FROM measures WHERE mest = %d AND rooi = %d ORDER BY dat DESC LIMIT 1;",DataType,room);
		if(DEBUG){cout << query << endl;}
	    mysql_query(&mysql,query);

	    //Déclaration des objets


	    unsigned int i = 0;
	    unsigned int num_champs = 0;

	    //On met le jeu de résultat dans le pointeur result
	    result = mysql_use_result(&mysql);
	    if(result)
	    {
	    //On récupère le nombre de champs
	    num_champs = mysql_num_fields(result);


		row = mysql_fetch_row(result);

		std::string svalue(row[2]);
		float fvalue=::atof(svalue.c_str());

		//Libération du jeu de résultat
		mysql_free_result(result);
		return fvalue;
	    }
	    else
	    {
	    	mysql_free_result(result);
	    	printf("Table not found\n");
	    	return -1;
	    }

	    //Libération du jeu de résultat
	    mysql_free_result(result);
	    return 0;


	//return myDBs->realTime[DataType][room];


}

float DB::getConf(int DataType, int room){

	return myDBs->config[DataType][room];
}

int DB::getMode(int DataType, int room){

	return myDBs->mode[DataType][room];
}

string DB::getUnit(int DataType)
{

	   //Requête qui sélectionne tout dans ma table
		char query[512];
		sprintf(query,"SELECT * FROM measuresTypes WHERE mest = %d;",DataType);
		//if(DEBUG){cout << query << endl;}

	    mysql_query(&mysql,query);

	    //Déclaration des objets


	    unsigned int i = 0;
	    unsigned int num_champs = 0;

	    //On met le jeu de résultat dans le pointeur result
	    result = mysql_use_result(&mysql);
	    if(result)
	    {
	    	//On récupère le nombre de champs
	    	num_champs = mysql_num_fields(result);

			row = mysql_fetch_row(result);

		    //Libération du jeu de résultat
		    mysql_free_result(result);
			return row[2];
	    }
	    else
	    {
	    	printf("Table not found\n");
	    	mysql_free_result(result);
	    	return "-1";
	    }

	    //Libération du jeu de résultat
	    mysql_free_result(result);
	    return "0";



	//return 	*myDBs->unit[DataType];
}





int DB::Connect()
{
    //Initialisation de MySQL
    mysql_init(&mysql);
    //Options de connexion
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"MYSQL_READ_DEFAULT_GROUP");

    //Si la connexion réussie...
    if(mysql_real_connect(&mysql,"localhost","domotic","domotic","domotic",0,NULL,0))
    {
    	printf("DB : Connected !\n");
    }
    else  //Sinon ...
    {
        printf("DB : Error !\n");
        return 2;
    }

    return 0;
}


int DB::Close()
{
        //Fermeture de MySQL
        mysql_close(&mysql);
        printf("DB : Closed !\n");

        return 0;
}


int DB::TableClear(string table)
{
	char query[512];
	sprintf(query,"TRUNCATE TABLE %s", table.c_str());
	if(DEBUG){cout << query << endl;}
    return mysql_query(&mysql,query);
}

int DB::TableToConsole(string table)
{
    //Requête qui sélectionne tout dans ma table
	char query[512];
	sprintf(query,"SELECT * FROM %s", table.c_str());
	if(DEBUG){cout << query << endl;}
    mysql_query(&mysql,query);

    //Déclaration des objets


    unsigned int i = 0;
    unsigned int num_champs = 0;

    //On met le jeu de résultat dans le pointeur result
    result = mysql_use_result(&mysql);
    if(result)
    {
    //On récupère le nombre de champs
    num_champs = mysql_num_fields(result);

		//Tant qu'il y a encore un résultat ...
		while ((row = mysql_fetch_row(result)))
		{
			//On déclare un pointeur long non signé pour y stocker la taille des valeurs
			unsigned long *lengths;

			//On stocke ces tailles dans le pointeur
			lengths = mysql_fetch_lengths(result);

			//On fait une boucle pour avoir la valeur de chaque champs
			for(i = 0; i < num_champs; i++)
			{
			   //On ecrit toutes les valeurs
			   printf("[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");
			}

			printf("\n");
		}
    }
    else
    {
    	printf("Table not found\n");
    }
    //Libération du jeu de résultat
    mysql_free_result(result);


        return 0;

}

int DB::setMeasuresTypesTable()
{

	this->TableClear("measuresTypes");

	this->setUnit(val_temperature,"°C","Température",-50,100);
	this->setUnit(val_humidity,"%","Humidité",0,100);
	this->setUnit(val_pressure,"mBar","Pression",800,1200);

    return 0;

}
