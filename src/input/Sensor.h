/**************************************************************************/
/*!
    @file     Sensor.h
    @author   M. Fegerl (Sensate Digital Solutions GmbH)
    @license  GPL (see LICENSE file)
    The Sensate ESP8266 firmware is used to connect ESP8266 based hardware 
    with the Sensate Cloud and the Sensate apps.

    ----> https://www.sensate.io

    SOURCE: https://github.com/sensate-io/firmware-esp8266.git

    @section  HISTORY
    v32 - Added MQTT Support!
    v29 - First Public Release
*/
/**************************************************************************/

#include <Arduino.h>

#ifndef _Sensor_h_
#define _Sensor_h_

#include "SensorCalculation.h"
#include "../communication/Data.h"

class SensorCalculation;

class Sensor {
  protected:
    unsigned int _refreshInterval;
    unsigned int _postDataInterval;
    float _smartValueThreshold;
    unsigned long lastTick;
    unsigned long lastPost;
    String _category;
    String _name;
    String _shortName;
    long _id;
    SensorCalculation* _calculation;
    virtual void preCycle(int);
    virtual Data* read(bool);
  public:
    Sensor (long, String, String, String, int, int, float, SensorCalculation*);
    int getRefreshInterval(void);
    int getPostDataInterval(void);
    long getId(void);
    String getName(void);
    String getShortName(void);
    String getCategory(void);
    String getMqttClass(void);
    String getMqttUnit(void);
    Data* trySensorRead(unsigned long, int);
    Data* forceSensorRead(unsigned long, int);
};

#endif