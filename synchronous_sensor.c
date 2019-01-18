#include "synchronous_sensor.h"
static SynchronousSensor mSynchronousSensors[MAX_SYNCHRONOUS_SENSORS_NUMBER];
static int mIterator = 0;




SynchronousSensor *SynchronousSensor_Create(char * (*getStringMeasure)(Sensor * const),char * (*getSensorType)(Sensor * const self)){

	SynchronousSensor *self = mSynchronousSensors + mIterator++;

	/*Creation*/
	self->super = Sensor_Create(getStringMeasure,getSensorType);

	/*Set Pure Inherited Methods*/
	self->isNewDataAvailable = self->super->isNewDataAvailable;
	self->setNewDataAvailable = self->super->setNewDataAvailable;
	self->setMeasurePointer = self->super->setMeasurePointer;
	self->getMeasure = self->super->getMeasure; 

	/*Set Overriden Methods*/

	/*Set Own Methods*/
	self->init = SynchronousSensor_init;
	self->setFrequency = SynchronousSensor_setFrequency;
	self->startMeasure = SynchronousSensor_startMeasure;
}

bool SynchronousSensor_init(SynchronousSensor * self,int mainTimerFrequency, int frequency){
	Sensor_init(self->super);
	self->mainTimerFrequency = mainTimerFrequency;
	self->frequency = frequency;
	self->numberOfMainTimerCycle = 0;
}


void SynchronousSensor_startMeasure(SynchronousSensor * const self){
	printf("Start measure");
	self->super->setNewDataAvailable(self->super,true);
}

bool SynchronousSensor_needToRefresh(SynchronousSensor * const self){
	self->numberOfMainTimerCycle++;	

	if((float)self->numberOfMainTimerCycle/(float)self->mainTimerFrequency >= 1.f/self->frequency){
		self->numberOfMainTimerCycle = 0;
		return true;
	}
	return false;
}


void SynchronousSensor_setFrequency(SynchronousSensor * const self, int frequency){
	self->frequency = frequency;
}


SynchronousSensor *SynchronousSensor_getSynchronousSensors(void){
	return mSynchronousSensors;
}

uint8_t SynchronousSensor_getSize(void){
	return mIterator;
}
