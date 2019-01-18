#include "barometer.h"

static Barometer mBarometers[MAX_BAROMETER_NUMBER];
static int mIterator = 0;

Barometer *Barometer_Create(){

	Barometer *self = mBarometers + mIterator++;
	
	/*Creation*/
	self->super = SynchronousSensor_Create(Barometer_getStringMeasure,Barometer_getSensorType);

	/*Set Pure Inherited Methods*/
	self->isNewDataAvailable = self->super->isNewDataAvailable;
	self->setNewDataAvailable = self->super->setNewDataAvailable;
	self->setMeasurePointer = self->super->setMeasurePointer;
	self->getMeasure = self->super->getMeasure;

	/*Set Overriden Methods*/
	self->super->init = self->init = Barometer_init;
	self->super->startMeasure = (self->startMeasure = Barometer_startMeasure);
	self->super->setFrequency = (self->setFrequency = Barometer_setFrequency);

	/*Init Measure Pointer*/
	self->super->setMeasurePointer(self->super->super, &(self->pressure));

	return self;
}

bool Barometer_init(SynchronousSensor * self,int mainTimerFrequency, int frequency){
	SynchronousSensor_init(self,mainTimerFrequency,frequency);
	
}


void Barometer_startMeasure(SynchronousSensor * const self){
	if(SynchronousSensor_needToRefresh(self)){
		Pressure *pressure = (Pressure *)(self->getMeasure(self->super));

		pressure->value = 0.5f;

		self->setNewDataAvailable(self->super, true);
	}
}

void Barometer_setFrequency(SynchronousSensor * const self, int frequency){
	self->setFrequency(self,frequency);
}

char* Barometer_getStringMeasure(Sensor * const self){
	static char result[100] = "";
	Pressure *pressure = (Pressure *)(self->getMeasure(self));
	sprintf(result,"BARO \tvalue -> %1.2f\r\n",pressure->value);
	return result;
	
}

char* Barometer_getSensorType(Sensor * const self){
	return "BAR";
}

Barometer *Barometer_getBarometers(void){
 	return mBarometers;
}

uint8_t Barometer_getSize(void){
	return mIterator;
}

