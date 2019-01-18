#include "timer.h"
static Timer mTimers[MAX_TIMERS_NUMBER];
static uint8_t mIterator;
static pthread_mutex_t monitor_handle = PTHREAD_MUTEX_INITIALIZER;


 void *timer_thread(void *id){
 	if(mTimers[(int)id].frequency != 0){
		while(1){
		//	printf("%lu\r\n",getMilliseconds());
			mTimers[(int)id].handler((int)id);
			Sleep((1.f/mTimers[(int)id].frequency)*1000.f);
		}
	}
	else {
		mTimers[(int)id].handler((int)id);
	}
	return NULL;
 }

uint8_t timer_add(void (*handler)(uint8_t), uint32_t frequency){
	Timer *timer = mTimers + mIterator;
	timer->handler = handler;
	timer->frequency = frequency;
	return mIterator++;
}

void timer_start(){
	struct sched_param params;
 	params.sched_priority = sched_get_priority_max(SCHED_FIFO);


	/*Threads Creation*/
	for(uint8_t i = 0 ; i < mIterator ; i++){
		pthread_create(&(mTimers[i].tid),NULL,timer_thread,(void *)(intptr_t)i);
		if(!pthread_setschedparam(mTimers[i].tid, SCHED_FIFO, &params)){
			printf("ERROR\r\n");	
		}
	}


	/*Threads Join*/
	for(uint8_t i = 0 ; i < mIterator ; i++){
		pthread_join(mTimers[i].tid,NULL);
	}
}
