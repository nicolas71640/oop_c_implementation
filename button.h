#ifndef DEF_BUTTON_DEF 
#define DEF_BUTTON_DEF

#include "asynchronous_sensor.h"
#include "interrupt.h"

/*PREPROCESSOR DIRECTIVES*/
#define MAX_BUTTONS_NUMBER 10

/*STRUCUTRES AND ENUMERATIONS*/
typedef struct Button Button;
struct Button{
	/*Base Class*/
	AsynchronousSensor *super;

	/*Attributes*/
	Interrupt *interrupt;
	bool clicked;

	/*Sensor Inherited Methods*/
	bool (*isNewDataAvailable)(Sensor * const self);
	void (*setNewDataAvailable)(Sensor * const self, bool newDataAvailable);
	void (*setMeasurePointer)(Sensor * const self, void * measurePointer);
	void * (*getMeasure)(Sensor * const self);

	/*Sensor Inherited Virtual Methods*/
	char * (*getStringMeasure)(Sensor * const self);
	char * (*getSensorType)(Sensor * const self);

	/*Asynchronous Sensor Inherited Public Methods*/
	bool (*init)(AsynchronousSensor * const self,int frequency);
	void (*start)(AsynchronousSensor * const self);
	void (*onDataReceived)(AsynchronousSensor * const self, char * data);

};

/*PROTOTYPES*/
Button *Button_Create();

/*Own Methods*/
bool Button_init(AsynchronousSensor * self, int frequency);
void Button_start(AsynchronousSensor * const self);
void Button_onDataReceived(AsynchronousSensor * const self, char * data);

/*Overrider Methods*/
char* Button_getStringMeasure(Sensor * const self);
char* Button_getSensorType(Sensor * const self);

/*ACCESSORS*/
Button *Button_getButtons(void);
uint8_t Button_getSize(void);



#endif
