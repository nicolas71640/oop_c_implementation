#include "asynchronous_sensor.h"
static AsynchronousSensor mAsynchronousSensors[MAX_ASYNCHRONOUS_SENSORS_NUMBER];
static int mIterator = 0;

/*PRIVATE FUNCTIONS*/

AsynchronousSensor *AsynchronousSensor_Create(char * (*getStringMeasure)(Sensor * const),char * (*getSensorType)(Sensor * const self)){

	AsynchronousSensor *self = mAsynchronousSensors + mIterator++;

	/*Creation*/
	self->super = Sensor_Create(getStringMeasure,getSensorType);

	/*Set Pure Inherited Methods*/
	self->isNewDataAvailable = self->super->isNewDataAvailable;
	self->setNewDataAvailable = self->super->setNewDataAvailable;
	self->setMeasurePointer = self->super->setMeasurePointer;
	self->getMeasure = self->super->getMeasure; 

	/*Set Overriden Methods*/
	self->getStringMeasure = getStringMeasure;
	self->getSensorType = getSensorType;

	/*Set Own Methods*/
	self->init = AsynchronousSensor_init;
	self->setFrequency = AsynchronousSensor_setFrequency;
	self->start = AsynchronousSensor_start;
}

bool AsynchronousSensor_init(AsynchronousSensor * self, int frequency){
	Sensor_init(self->super);
	self->frequency = frequency;

}


void AsynchronousSensor_start(AsynchronousSensor * const self){
	printf("Start");
}


void AsynchronousSensor_onDataReceived(AsynchronousSensor * const self, char * data){
	self->super->setNewDataAvailable(self->super,true);
}

void AsynchronousSensor_setFrequency(AsynchronousSensor * const self, int frequency){
	self->frequency = frequency;
}


AsynchronousSensor *AsynchronousSensor_getAsynchronousSensors(void){
	return mAsynchronousSensors;
}

uint8_t AsynchronousSensor_getSize(void){
	return mIterator;
}
