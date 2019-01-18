#include "observer.h"
static Observer mObservers[MAX_OBSERVERS_NUMBER];
static int mIterator = 0;

/* 
*	\brief Init the suject
*/
Observer *Observer_Create(void){
	Observer *self = mObservers + mIterator++;
	self->init=Observer_init;
	return self;
}


bool Observer_init(Observer * const self, void (*handler)(void *,void *),void * object_instance){
	self->object_instance = object_instance;
	self->handler = handler;
}

