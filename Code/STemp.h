#include <OneWire.h>
#include <DallasTemperature.h>

#define sensor_temperatura1 45 //Poner pin que corresponda
#define sensor_temperatura2 43 //Poner pin que corresponda

OneWire oneWireObjeto1(sensor_temperatura1);
OneWire oneWireObjeto2(sensor_temperatura2);

DallasTemperature sensorDS18B20_1(&oneWireObjeto1);
DallasTemperature sensorDS18B20_2(&oneWireObjeto2);

void TEMP_SENSORS_BEGIN(byte resolution){
  sensorDS18B20_1.setResolution(resolution);
  delay(100);
  sensorDS18B20_1.begin();
  sensorDS18B20_2.begin();
}

float _t1(){
  sensorDS18B20_1.requestTemperatures();
  delay(100);
  return sensorDS18B20_1.getTempCByIndex(0);
}

float _t2(){
  sensorDS18B20_2.requestTemperatures();
  delay(100);
  return sensorDS18B20_2.getTempCByIndex(0);
}