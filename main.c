#include "main.h"

void testObserver(void){
	printf("FIRST OBSERVER\r\n");
}

void testObserver2(void){
	printf("SECOND OBSERVER\r\n");
}

void main(void){
	//SynchronousSensor button; 
	//SynchronousSensor_Create(&button);
       	//button.addObserver(&button,testObserver);
	//button.notifyObservers(&button);
	//button.deleteObserver(&button,testObserver);
	////button.addObserver(&button,testObserver2);
	//button.cleanObservers(&button);
       	//button.notifyObservers(&button);
	////button.deleteObserver(&button,testObserver);

//	Sensor rfid;
//	Sensor_Create(&rfid);
//	rfid.addObserver(&rfid,testObserver2);
//	rfid.notifyObservers(&rfid);

	/*Synchronous Sensor*/
//	Accelerometer accelerometer;
//	Accelerometer_Create(&accelerometer);
//	accelerometer.init(&accelerometer, 100);
//	accelerometer.startMeasure(&accelerometer);
//	if(accelerometer.isNewDataAvailable(&accelerometer))
//		printf("%f\r\n",((Accelerations *)(accelerometer.getMeasure(&accelerometer)))->X);
//	if(accelerometer.isNewDataAvailable(&accelerometer))
//		printf("%f\r\n",((Accelerations *)(accelerometer.getMeasure(&accelerometer)))->X);
	printf("THREADS START\r\n");
	pthread_t environment_tid;
	pthread_t equimetre_tid;
        pthread_create(&environment_tid,NULL,environment_main,NULL);
	pthread_create(&equimetre_tid,NULL,equimetre_init,NULL); 

        pthread_join(environment_tid,NULL);
        pthread_join(equimetre_tid,NULL);

	while(1)
		Sleep(10);

		
}




