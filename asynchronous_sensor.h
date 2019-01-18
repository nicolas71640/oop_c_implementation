#ifndef DEF_ASYNCHRONOUS_SENSOR_DEF 
#define DEF_ASYNCHRONOUS_SENSOR_DEF

#include "sensor.h"
#include "timer.h"

/*PREPROCESSOR DIRECTIVES*/
#define MAX_ASYNCHRONOUS_SENSORS_NUMBER 10

/*STRUCUTRES AND ENUMERATIONS*/
typedef struct AsynchronousSensor AsynchronousSensor;
struct AsynchronousSensor{
	/*Base Class*/
	Sensor *super;

	/*Attributes*/
	int frequency;

	/*Sensor Inherited Methods*/
	bool (*isNewDataAvailable)(Sensor * const self);
	void (*setNewDataAvailable)(Sensor * const self, bool newDataAvailable);
	void (*setMeasurePointer)(Sensor * const self, void * measurePointer);
	void * (*getMeasure)(Sensor * const self);

	/*Sensor Inherited Virtual Methods*/
	char * (*getStringMeasure)(Sensor * const self);
	char * (*getSensorType)(Sensor * const self);

	/*Public Methods*/
	bool (*init)(AsynchronousSensor * const self,int frequency);
	void (*start)(AsynchronousSensor * const self);
	void (*setFrequency)(AsynchronousSensor * const self, int frequency);
	void (*onDataReceived)(AsynchronousSensor * const self, char * data);

};

/*PROTOTYPES*/
AsynchronousSensor *AsynchronousSensor_Create(char * (*getStringMeasure)(Sensor * const),char * (*getSensorType)(Sensor * const self));

/*Overriden Methods*/
void * AsynchronousSensor_getMeasure(Sensor * const self);

/*Own Methods*/
bool AsynchronousSensor_init(AsynchronousSensor * self, int frequency);
void AsynchronousSensor_setFrequency(AsynchronousSensor * const self, int frequency);
void AsynchronousSensor_start(AsynchronousSensor * const self);
void AsynchronousSensor_onDataReceived(AsynchronousSensor * const self, char * data);

/*Protected Methods*/
bool AsynchronousSensor_needToRefresh(AsynchronousSensor * const self);

/*ACCESSORS*/
AsynchronousSensor *AsynchronousSensor_getAsynchronousSensors(void);
uint8_t AsynchronousSensor_getSize(void);



#endif
