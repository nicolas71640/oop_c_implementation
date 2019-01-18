#ifndef DEF_BAROMETER
#define DEF_BAROMETER

#include "synchronous_sensor.h"

/*PREPROCESSOR DIRECTIVES*/ 
#define MAX_BAROMETER_NUMBER 1

/*STRUCUTRES AND ENUMERATIONS*/
typedef struct{
	float value;
}Pressure;

typedef struct Barometer Barometer;
struct Barometer{
	/*Base Class*/
	SynchronousSensor *super;

	/*Attributes*/
	Pressure pressure;

	/*Sensor Inherited Methods*/
	bool (*isNewDataAvailable)(Sensor * const self);
	void (*setNewDataAvailable)(Sensor * const self, bool newDataAvailable);
	void (*setMeasurePointer)(Sensor * const self, void * measurePointer);
	void * (*getMeasure)(Sensor * const self);
	char * (*getStringMeasure)(Sensor * const self);
	char * (*getSensorType)(Sensor * const self);

	/*SynchronousSensor Inherited Methods*/
	bool (*init)(SynchronousSensor * self,int mainTimerFrequency, int frequency);
	void (*startMeasure)(SynchronousSensor * const self);
	void (*setFrequency)(SynchronousSensor  * const self, int frequency);

	/*Public Methods*/
	

};

/*PROTOTYPES*/
Barometer *Barometer_Create();

/*Overriden Methods*/
void * Barometer_getMeasure(Sensor * const self);
bool Barometer_init(SynchronousSensor * self,int mainTimerFrequency, int frequency);
void Barometer_startMeasure(SynchronousSensor * const self);
void Barometer_setFrequency(SynchronousSensor * const self, int frequency);
char* Barometer_getStringMeasure(Sensor * const self);
char* Barometer_getSensorType(Sensor * const self);

/*Own Methods*/


/*ACCESSORS*/
Barometer *Barometer_getBarometers(void);
uint8_t Barometer_getSize(void);
#endif
