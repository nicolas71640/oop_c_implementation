#ifndef DEF_GPS
#define DEF_GPS

#include "asynchronous_sensor.h"
#include "usart.h"

/*PREPROCESSOR DIRECTIVES*/ 
#define MAX_GPS_NUMBER 1

/*STRUCUTRES AND ENUMERATIONS*/
typedef struct{
	float latitude;
	float longitude;
	float elevation;
}Coordinates;

typedef struct Gps Gps;
struct Gps{
	/*Base Class*/
	AsynchronousSensor *super;

	/*Attributes*/
	Usart *usart;
	Coordinates coordinates;

	/*Sensor Inherited Methods*/
	bool (*isNewDataAvailable)(Sensor * const self);
	void (*setNewDataAvailable)(Sensor * const self, bool newDataAvailable);
	void (*setMeasurePointer)(Sensor * const self, void * measurePointer);
	void * (*getMeasure)(Sensor * const self);
	char * (*getStringMeasure)(Sensor * const self);
	char * (*getSensorType)(Sensor * const self);

	/*AsynchronousSensor Inherited Methods*/
	void (*start)(AsynchronousSensor * const self);
	void (*setFrequency)(AsynchronousSensor  * const self, int frequency);
	void (*onDataReceived)(AsynchronousSensor * const self, char * data);

	/*Public Methods*/
	bool (*init)(Gps* self, int frequency);
	

};

/*PROTOTYPES*/
Gps *Gps_Create();

/*Overriden Methods*/
void * Gps_getMeasure(Sensor * const self);
bool Gps_init(Gps * self, int frequency);
void Gps_start(AsynchronousSensor * const self);
void Gps_setFrequency(AsynchronousSensor * const self, int frequency);
char* Gps_getStringMeasure(Sensor * const self);
char* Gps_getSensorType(Sensor * const self);
void Gps_onDataReceived(AsynchronousSensor * const self, char * data);

/*Own Methods*/


/*ACCESSORS*/
Gps *Gps_getGpss(void);
uint8_t Gps_getSize(void);
#endif
