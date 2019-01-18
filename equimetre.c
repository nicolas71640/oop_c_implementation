#include "equimetre.h"

Accelerometer *mAccelerometer;
Barometer *mBarometer;
Gps *mGps;
Button *mButton;


/*PRIVATE FUNCTIONS*/
void power_manage(void);

void power_manage(void){
	Sleep(1);
}

void equimetre_timer_interrupt(uint8_t timerId){
	/*Synchronous Sensors*/
	SynchronousSensor *synchronousSensors = SynchronousSensor_getSynchronousSensors();
	for(uint8_t i = 0 ; i < SynchronousSensor_getSize(); i++){
		synchronousSensors[i].startMeasure(&(synchronousSensors[i]));	
	}
}


void equimetre_main(uint8_t timerId){
	printf("EQUIMETRE MAIN START\r\n");
	/*Main Equimetre Loop*/
	for(;;){
		/*Sensors*/
		Sensor *sensors = Sensor_getSensors();
		for(uint8_t i = 0 ; i < Sensor_getSize(); i++){
			if(sensors[i].isNewDataAvailable(&(sensors[i]))){
				sensors[i].getMeasure(&(sensors[i]));	
				//printf(sensors[i].getStringMeasure(&(sensors[i])));
			}
		}

		power_manage();
	}


}/*equimetre_main*/


void *equimetre_init(void *id){
	printf("EQUIMETRE INIT\r\n");

	/*Accelerometer*/
	mAccelerometer = Accelerometer_Create();	
	mAccelerometer->init(mAccelerometer->super,MAIN_TIMER_FREQUENCY,1);

	/*Barometer*/
	mBarometer = Barometer_Create();	
	mBarometer->init(mBarometer->super,MAIN_TIMER_FREQUENCY,1); 

	/*GPS*/
	mGps = Gps_Create();
	mGps->init(mGps,5);

	/*Button*/
	mButton = Button_Create();

	//Main Timer
	timer_add(equimetre_main,0);
	timer_add(equimetre_timer_interrupt,MAIN_TIMER_FREQUENCY);
	timer_start();

}
