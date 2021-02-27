#include <Arduino.h>
#include <STemp.h>

void setup(){
  TEMP_SENSORS_BEGIN(10);
  HS1.begin();
  Sensor_2.begin();
}

void loop(){

}
