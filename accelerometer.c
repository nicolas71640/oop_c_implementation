#include "accelerometer.h"
static Accelerometer mAccelerometers[MAX_ACCELEROMETER_NUMBER];
static int mIterator = 0;

Accelerometer *Accelerometer_Create(){

	Accelerometer *self = mAccelerometers + mIterator++;
	
	/*Creation*/
	self->super = SynchronousSensor_Create(Accelerometer_getStringMeasure,Accelerometer_getSensorType);


	/*Set Pure Inherited Methods*/
	self->isNewDataAvailable = self->super->isNewDataAvailable;
	self->setNewDataAvailable = self->super->setNewDataAvailable;
	self->setMeasurePointer = self->super->setMeasurePointer;
	self->getMeasure = self->super->getMeasure;

	/*Set Overriden Methods*/
	self->super->init = self->init = Accelerometer_init;
	self->super->startMeasure = (self->startMeasure = Accelerometer_startMeasure);
	self->super->setFrequency = (self->setFrequency = Accelerometer_setFrequency);
	self->super->getStringMeasure = self->super->super->getStringMeasure = self->getStringMeasure = Accelerometer_getStringMeasure;
	self->super->getSensorType = self->super->super->getSensorType = self->getSensorType= Accelerometer_getSensorType;

	/*Init Measure Pointer*/
	self->super->setMeasurePointer(self->super->super, &(self->accelerations));

	return self;
}

bool Accelerometer_init(SynchronousSensor * self,int mainTimerFrequency, int frequency){
	SynchronousSensor_init(self,mainTimerFrequency,frequency);
	
}


void Accelerometer_startMeasure(SynchronousSensor * const self){
	if(SynchronousSensor_needToRefresh(self)){
		//printf("ACC : Start Measure\r\n");
		Accelerations *accelerations = (Accelerations *)(self->getMeasure(self->super));

		accelerations->X = 0.5f;
		accelerations->Y = 0.2f;
		accelerations->Z = 0.1f;

		self->setNewDataAvailable(self->super, true);
	}
}

void Accelerometer_setFrequency(SynchronousSensor * const self, int frequency){
	self->setFrequency(self,frequency);
}

char* Accelerometer_getStringMeasure(Sensor * const self){
	static char result[100] = "";
	Accelerations *accelerations = (Accelerations *)(self->getMeasure(self));
	sprintf(result,"ACC \tX -> %1.2f\tY -> %1.2f\tZ -> %1.2f\r\n",accelerations->X,accelerations->Y,accelerations->Z);
	return result;
	
}

char* Accelerometer_getSensorType(Sensor * const self){
	return "ACC";
}

Accelerometer *Accelerometer_getAccelerometers(void){
 	return mAccelerometers;
}

uint8_t Accelerometer_getSize(void){
	return mIterator;
}

