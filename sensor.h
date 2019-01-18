#ifndef DEF_SENSOR_H
#define DEF_SENSOR_H

#include "subject.h"
#include "util.h"

/*PREPROCESSOR DIRECTIVES*/
#define MAX_SENSORS_NUMBER 10

/*STRUCTURES AND ENUMERATIONS*/
typedef struct Sensor Sensor;
struct Sensor{
	/*Attributes*/
	void * measure;
	bool newDataAvailable;
	uint16_t measuredFrequency;


	/*Public Methods*/
	bool (*init)(Sensor * const self);
	bool (*isNewDataAvailable)(Sensor * const self);
	void (*setNewDataAvailable)(Sensor * const self, bool newDataAvailable);
	void (*setMeasurePointer)(Sensor * const self, void * measurePointer);
	void * (*getMeasure)(Sensor * const self);

	/*Virtual Methods*/
	char * (*getStringMeasure)(Sensor * const self);
	char * (*getSensorType)(Sensor * const self);
	
};

/*PROTOTYPES*/
Sensor *Sensor_Create(char * (*getStringMeasure)(Sensor * const),char * (*getSensorType)(Sensor * const self));
bool Sensor_init(Sensor * const self);
bool Sensor_isNewDataAvailable(Sensor * const self);
void Sensor_setNewDataAvailable(Sensor * const self, bool newDataAvailable);
void Sensor_setMeasurePointer(Sensor * const self, void * measurePointer);
void * Sensor_getMeasure(Sensor * const self);

/*STATIC METHODS*/
Sensor* Sensor_getSensors(void);
uint8_t Sensor_getSize(void);
void Sensor_measureFrequency(void);

#endif
