#ifndef DEF_ACCELEROMETER
#define DEF_ACCELEROMETER

#include "synchronous_sensor.h"

/*PREPROCESSOR DIRECTIVES*/ 
#define MAX_ACCELEROMETER_NUMBER 1

/*STRUCUTRES AND ENUMERATIONS*/
typedef struct{
	float X;
	float Y;
	float Z;
}Accelerations;

typedef struct Accelerometer Accelerometer;
struct Accelerometer{
	/*Base Class*/
	SynchronousSensor *super;

	/*Attributes*/
	Accelerations accelerations;

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
Accelerometer *Accelerometer_Create();

/*Overriden Methods*/
void * Accelerometer_getMeasure(Sensor * const self);
bool Accelerometer_init(SynchronousSensor * self,int mainTimerFrequency, int frequency);
void Accelerometer_startMeasure(SynchronousSensor * const self);
void Accelerometer_setFrequency(SynchronousSensor * const self, int frequency);
char* Accelerometer_getStringMeasure(Sensor * const self);
char* Accelerometer_getSensorType(Sensor * const self);

/*Own Methods*/


/*ACCESSORS*/
Accelerometer *Accelerometer_getAccelerometers(void);
uint8_t Accelerometer_getSize(void);
#endif
