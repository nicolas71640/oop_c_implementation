#ifndef DEF_SYNCHRONOUS_SENSOR_DEF 
#define DEF_SYNCHRONOUS_SENSOR_DEF

#include "sensor.h"

/*PREPROCESSOR DIRECTIVES*/
#define MAX_SYNCHRONOUS_SENSORS_NUMBER 10

/*STRUCUTRES AND ENUMERATIONS*/
typedef struct SynchronousSensor SynchronousSensor;
struct SynchronousSensor{
	/*Base Class*/
	Sensor *super;

	/*Attributes*/
	int mainTimerFrequency;
	int frequency;
	int numberOfMainTimerCycle;

	/*Sensor Inherited Methods*/
	bool (*isNewDataAvailable)(Sensor * const self);
	void (*setNewDataAvailable)(Sensor * const self, bool newDataAvailable);
	void (*setMeasurePointer)(Sensor * const self, void * measurePointer);
	void * (*getMeasure)(Sensor * const self);

	/*Sensor Inherited Virtual Methods*/
	char * (*getStringMeasure)(Sensor * const self);
	char * (*getSensorType)(Sensor * const self);

	/*Public Methods*/
	bool (*init)(SynchronousSensor * const self,int mainTimerFrequency,int frequency);
	void (*startMeasure)(SynchronousSensor * const self);
	void (*setFrequency)(SynchronousSensor * const self, int frequency);

};

/*PROTOTYPES*/
SynchronousSensor *SynchronousSensor_Create(char * (*getStringMeasure)(Sensor * const),char * (*getSensorType)(Sensor * const self));

/*Overriden Methods*/
void * SynchronousSensor_getMeasure(Sensor * const self);

/*Own Methods*/
bool SynchronousSensor_init(SynchronousSensor * self,int mainTimerFrequency, int frequency);
void SynchronousSensor_setFrequency(SynchronousSensor * const self, int frequency);
void SynchronousSensor_startMeasure(SynchronousSensor * const self);

/*Protected Methods*/
bool SynchronousSensor_needToRefresh(SynchronousSensor * const self);

/*ACCESSORS*/
SynchronousSensor *SynchronousSensor_getSynchronousSensors(void);
uint8_t SynchronousSensor_getSize(void);



#endif
