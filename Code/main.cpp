#include <Arduino.h>
#include <STemp.h>
#include "uTimerLib.h"

#define Min_temp_1 0 //Temperatura minima de isteresis sensor 1
#define Max_temp_1 0 //Temperatura maxima de isteresis sensor 1
#define Min_temp_2 0 //Temperatura minima de isteresis sensor 2
#define Max_temp_2 0 //Temperatura maxima de isteresis sensor 2

#define Min_hum_1 0 //Temperatura minima de isteresis sensor 1
#define Max_hum_1 0 //Temperatura maxima de isteresis sensor 1
#define Min_hum_2 0 //Temperatura minima de isteresis sensor 2
#define Max_hum_2 0 //Temperatura maxima de isteresis sensor 2

#define Relay_T1 0 //Rele temperatura sensor 1
#define Relay_T2 0 //Rele temperatura sensor 2
#define Relay_H1 0 //Rele humedad sensor 1
#define Relay_H2 0 //Rele humedad sensor 2

#define awa1 0 //Pin sensor AwA 1
#define awa2 0 //Pin sensor AwA 2

int T1 = 0;
int T2 = 0;
int H1 = 0;
int H2 = 0;
int _A1 = 0;
int _A2 = 0;

boolean T1I = false;
boolean T2I = false;

boolean H1I = false;
boolean H2I = false;

/**********************************************************************/
/*                         Control de tiempo                          */
/**********************************************************************/

void Interrupcion();
#define TContSensores 100 //Conteo para actrualizar sensores con base de 2ms
byte TickSensores;
byte ContSensores;

#define TContDisplay 5 //Conteo para actualizar el display con base de 200ms
byte TickDisplay;
byte ContDisplay;
/**********************************************************************/
/**********************************************************************/

#include <lcd.h>

void setup(){
    pinMode(Relay_T1, OUTPUT);
    pinMode(Relay_T2, OUTPUT);
    pinMode(Relay_H1, OUTPUT);
    pinMode(Relay_H2, OUTPUT);
    PinMode(awa1, INPUT);
    PinMode(awa2, INPUT);
    
    TEMP_SENSORS_BEGIN(10);
    HS1.begin();
    Sensor_2.begin();
    TimerLib.setInterval_us(Interrupcion, 2000);
    setupLCD();
}

void loop(){
    if (TickSensores == 1){
        TickSensores = 0;
        T1 = int(_t1());
        T2 = int(_t2());
        H1 = int(_h1());
        H2 = int(_h2());
        _A1 = analogRead(awa1);
        _A2 = analogRead(awa2);
        /*************************************************************************/
        if((Max_temp_1 < T1) && T1I == false){ //Temperatura alta
            digitalWrite(Relay_T1, HIGH);
            T1I = true;
        }
        
        if((Min_temp_1 > T1) && T1I == true){ //Temperatura baja
            digitalWrite(Relay_T1, LOW);
            T1I = false;
        }
        
        if((Max_temp_2 < T2) && T2I == false){ //Temperatura alta
            digitalWrite(Relay_T2, HIGH);
            T2I = true;
        }
        
        if((Min_temp_2 > T2) && T2I == true){ //Temperatura baja
            digitalWrite(Relay_T2, LOW);
            T2I = false
        }
        /*************************************************************************/
        if((Max_hum_1 < H1) && H1I == false){ //Humedad alta
            digitalWrite(Relay_H1, HIGH);
            H1I = true;
        }
        
        if((Min_hum_1 > H1) && H1I == true){ //Humedad baja
            digitalWrite(Relay_H1, LOW);
            H1I = false;
        }
        
        if((Max_hum_2 < H2) && H2I == false){ //Humedad alta
            digitalWrite(Relay_H2, LOW);
            H2I = true;
        }
        
        if((Min_hum_2 > H2) && H2I == true){ //Humedad baja
            digitalWrite(Relay_H2, LOW);
            H2I = false;
        }
        /*************************************************************************/
        if((Max_awa_1 < _A1) && A1I == false){ //AwA alta
            digitalWrite(Relay_A1, HIGH);
            A1I = true;
        }

        if((Min_awa_1 > _A1) && A1I == true){ //AwA baja
            digitalWrite(Relay_A1, LOW);
            A1I = false;
        }
        
        if((Min_awa_2 > _A2) && A2I == false){ //AwA alta
            digitalWrite(Relay_A2, HIGH);
            A2I = false;
        }
        
        if((Min_awa_2 > _A2) && A2I == true){ //AwA baja
            digitalWrite(Relay_A2, LOW);
            A2I = false;
        }
        /*************************************************************************/
    }
    
    if (TickDisplay == 1){
        TickDisplay = 0;
        ControlLCD();
    }
}

void Interrupcion(){
    ContSensores++;
    if (ContSensores >= TContSensores){
        TickSensores = 1;
        ContSensores = 0;
        ContDisplay++;
        if (ContDisplay >= TContDisplay){
            TickDisplay = 1;
            ContDisplay = 0;
        }
    }
}
