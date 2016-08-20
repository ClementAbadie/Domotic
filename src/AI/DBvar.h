
#ifndef AI_DBVAR_H_
#define AI_DBVAR_H_


#define MAX_DATA_TYPE 36
#define MAX_CONFIG_VALUE 36
#define MAX_ROOM 20
#define MAX_MEASURE_INFO 3

#define ID 1
#define Mtime 2

//RealTimeValue
#define val_temperature 1
#define val_humidity 2
#define val_pressure 3


//Configs values

#define conf_refreshWaitingTime 60

#define conf_temperatureLow 1
#define conf_temperatureHigh 2

#define conf_humidityLow 4
#define conf_humidityHigh 5

#define conf_pressureLow 7
#define conf_pressureHigh 8


//Modes

#define mode_off 0
#define mode_on
#define mode_auto 2


//Rooms

#define room_salon 1
#define room_chambre 2
#define room_sdb 3


//Plugs

#define plug_dehumidifier_nb 1
#define plug_dehumidifier_gr 1
#define plug_antimoskito_nb 2
#define plug_antimoskito_gr 1
#define plug_charger_nb 3
#define plug_charger_gr 1

//Calibrate

#define calibration_linear_temperature -3.4



//Pushbullet

#define Pushbullet_APIKEY "o.22ZQASFygvZFMX1BBW3XVBrYpOSgcYI4"

#endif
