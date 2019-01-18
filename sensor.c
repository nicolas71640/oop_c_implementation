#include "sensor.h"
static Sensor mSensors[MAX_SENSORS_NUMBER];
static int mIterator = 0;

Sensor *Sensor_Create(char * (*getStringMeasure)(Sensor * const),char * (*getSensorType)(Sensor * const self)){
	Sensor *self = mSensors + mIterator++;
	
	self->init = Sensor_init;
	self->isNewDataAvailable = Sensor_isNewDataAvailable;
	self->setNewDataAvailable = Sensor_setNewDataAvailable;
	self->getMeasure = Sensor_getMeasure;
	self->setMeasurePointer = Sensor_setMeasurePointer;
	self->getStringMeasure = getStringMeasure;
	self->getSensorType = getSensorType;

	return self;
}

bool Sensor_init(Sensor * const self){
	self->newDataAvailable = false;
	return true;
}

bool Sensor_isNewDataAvailable(Sensor * const self){
	return self->newDataAvailable;
}

void Sensor_setNewDataAvailable(Sensor * const self, bool newDataAvailable){
	self->measuredFrequency++;
	Sensor_measureFrequency();
	self->newDataAvailable = newDataAvailable;
}

void * Sensor_getMeasure(Sensor * const self){
	self->newDataAvailable = false;
	return self->measure;
}

void Sensor_setMeasurePointer(Sensor * const self, void * measurePointer){
	self->measure = measurePointer;
}


Sensor* Sensor_getSensors(void){
	return mSensors;
}

uint8_t Sensor_getSize(void){
	return mIterator;
}

void Sensor_measureFrequency(void){
	char result[200] = "";
	char temp [20] = "";
	static uint32_t lastSeconds = 0;

	if(lastSeconds != getSeconds()){
		lastSeconds = getSeconds();
		for(uint8_t i = 0 ; i<mIterator ; i++){
			sprintf(temp,"%s : %uHz\t ",mSensors[i].getSensorType(&(mSensors[i])),mSensors[i].measuredFrequency);
			strcat(result,temp);
			mSensors[i].measuredFrequency = 0;
		}
		printf("%s\r\n",result);

	}
}
