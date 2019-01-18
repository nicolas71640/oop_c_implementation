#include "button.h"

static Button mButtons[MAX_BUTTONS_NUMBER];
static int mIterator = 0;

Button *Button_Create(){

	Button *self = mButtons + mIterator++;
	
	/*Creation*/
	self->super = AsynchronousSensor_Create(Button_getStringMeasure,Button_getSensorType);
	self->interrupt = Interrupt_Create();


	/*Set Pure Inherited Methods*/
	self->isNewDataAvailable = self->super->isNewDataAvailable;
	self->setNewDataAvailable = self->super->setNewDataAvailable;
	self->setMeasurePointer = self->super->setMeasurePointer;
	self->getMeasure = self->super->getMeasure;

	/*Set Overriden Methods*/
	self->super->init = self->init = Button_init;
	self->super->start= (self->start= Button_start);
	self->super->onDataReceived = (self->onDataReceived = Button_onDataReceived);

	/*Init Measure Pointer*/
	self->super->setMeasurePointer(self->super->super, &(self->clicked));


	/*Init Interrupt*/
	self->interrupt->addObserver(self->interrupt,self->super,(void(*)(void*,void*))self->onDataReceived);

	return self;
}

bool Button_init(AsynchronousSensor * self, int frequency){
	//AsynchronousSensor_init(self,frequency);
}


void Button_start(AsynchronousSensor * const self){
	printf("BUTTON : Start \r\n");
}

void Button_onDataReceived(AsynchronousSensor * const self, char * data){
	AsynchronousSensor_onDataReceived(self,data);
}


char* Button_getStringMeasure(Sensor * const self){
	static char result[100] = "";
	sprintf(result,"BUTTON CLICKED\r\n"); 
	return result;
	
}

char* Button_getSensorType(Sensor * const self){
	return "BUTTON";
}

Button *Button_getButtons(void){
 	return mButtons;
}

uint8_t Button_getSize(void){
	return mIterator;
}

