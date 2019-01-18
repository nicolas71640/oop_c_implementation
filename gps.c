#include "gps.h"

static Gps mGpss[MAX_GPS_NUMBER];
static int mIterator = 0;

Gps *Gps_Create(){

	Gps *self = mGpss + mIterator++;
	
	/*Creation*/
	self->super = AsynchronousSensor_Create(Gps_getStringMeasure,Gps_getSensorType);
	self->usart = Usart_Create();

	/*Set Pure Inherited Methods*/
	self->isNewDataAvailable = self->super->isNewDataAvailable;
	self->setNewDataAvailable = self->super->setNewDataAvailable;
	self->setMeasurePointer = self->super->setMeasurePointer;
	self->getMeasure = self->super->getMeasure;

	/*Set Overriden Methods*/
	self->init = Gps_init;
	self->super->start= (self->start= Gps_start);
	self->super->setFrequency = (self->setFrequency = Gps_setFrequency);
	self->super->onDataReceived = (self->onDataReceived = Gps_onDataReceived);

	/*Init Measure Pointer*/
	self->super->setMeasurePointer(self->super->super, &(self->coordinates));

	return self;
}

bool Gps_init(Gps * self, int frequency){
	AsynchronousSensor_init(self->super,frequency);

	/*Init Usart*/
	self->usart->init(self->usart,frequency);
	self->usart->addObserver(self->usart,self->super,(void(*)(void*,void*))self->onDataReceived);
}


void Gps_start(AsynchronousSensor * const self){
	printf("GPS : Start \r\n");
	Coordinates *coordinates = (Coordinates *)(self->getMeasure(self->super));
}

void Gps_onDataReceived(AsynchronousSensor * const self, char * data){
	Coordinates *coordinates = (Coordinates *)(self->getMeasure(self->super));

	coordinates->latitude = 1.f;
	coordinates->longitude = 2.f;
	coordinates->elevation = 3.f;

	/*Have to be at the end, to toggle the NewDataAvailable field*/
	AsynchronousSensor_onDataReceived(self,data);

}

void Gps_setFrequency(AsynchronousSensor * const self, int frequency){
	self->setFrequency(self,frequency);
}

char* Gps_getStringMeasure(Sensor * const self){
	static char result[100] = "";
	Coordinates *coordinates = (Coordinates *)(self->getMeasure(self));
	sprintf(result,"GPS \tLAT -> %1.2f\tLON -> %1.2f\tELE -> %1.2f\r\n",coordinates->latitude,coordinates->longitude,coordinates->elevation);
	return result;
	
}

char* Gps_getSensorType(Sensor * const self){
	return "GPS";
}

Gps *Gps_getGpss(void){
 	return mGpss;
}

uint8_t Gps_getSize(void){
	return mIterator;
}

