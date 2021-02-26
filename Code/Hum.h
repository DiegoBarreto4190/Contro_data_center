#include <Adafruit_Sensor.h>
#include <DHT.h>

#define Sensor_1 0 //Colocar el pin que corresponda
#define Sensor_2 1 //Colocar el pin que corresponda

DHT HS1(Sensor_1, DHT21);
DHT HS2(Sensor_2, DHT21);

loat _H1(){
  return HS1.readHumidity();
}

float _H2(){
  return HS2.readHumidity();
}
