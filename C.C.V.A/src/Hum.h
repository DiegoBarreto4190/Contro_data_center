//#include <Adafruit_Sensor.h>
#include <DHT.h>
//#include <AM2320.h>
#define Sensor_1 A2 //Colocar el pin que corresponda
#define Sensor_2 A3

DHT HS1(Sensor_1, DHT21);
DHT HS2(Sensor_2, DHT21);

float _h1(){
  return HS1.readHumidity();
}

float _h2(){
  return HS2.readHumidity();
}
