#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <AM2320.h

#define Sensor_1 0 //Colocar el pin que corresponda
AM2320 Sensor_2;

DHT HS1(Sensor_1, DHT21);

float _H1(){
  return HS1.readHumidity();
}

float _H1(){
  if (Sensor_2.easure()) {
    return(Sensor_2.getHumidity());
  }
}
