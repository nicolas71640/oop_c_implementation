#include "util.h"

uint32_t getMilliseconds(void){
	struct timeval time;
	gettimeofday(&time,NULL);
	return (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
}

uint32_t getSeconds(void){
	struct timeval time;
	gettimeofday(&time,NULL);
	return (time.tv_sec);
}



