#include "subject.h"
static Subject mSubjects[MAX_SUBJECTS_NUMBER];
static int mIterator = 0;

/* 
*	\brief Init the suject
*/
Subject *Subject_Create(void){

	Subject *self = mSubjects + mIterator++;

	self->addObserver = Subject_addObserver;
	self->deleteObserver = Subject_deleteObserver;
	self->cleanObservers = Subject_cleanObservers;
	self->notifyObservers = Subject_notifyObservers;
	memset(self->observers,0,sizeof(self->observers));

	return self;
}

/* 
*	\brief Add an observer
*/
bool Subject_addObserver(Subject * const self, Observer *observer){
	for(uint8_t i = 0 ; i < NUMBER_OF_OBSERVERS_MAX ; i++){
		if(!(self->observers[i])){
			self->observers[i] = observer;
			return true;
		}
	}
	return false;
}

/* 
*	\brief Delete a specific observer
*/
bool Subject_deleteObserver(Subject * const self, Observer *observer){
	for(uint8_t i = 0 ; i < NUMBER_OF_OBSERVERS_MAX ; i++){
		if(self->observers[i] == observer)
		{
			self->observers[i] = NULL; 
			return true;
		}
	}
	return false;
}

void Subject_cleanObservers(Subject * const self){
	for(uint8_t i = 0 ; i < NUMBER_OF_OBSERVERS_MAX ; i++){
		self->observers[i] = NULL;
	}
}

/* 
*	\brief Notify all the observers
*/
void Subject_notifyObservers(Subject * const self,void *data){
	for(uint8_t i = 0 ; i < NUMBER_OF_OBSERVERS_MAX ; i++){
		if(self->observers[i]){
			self->observers[i]->handler(self->observers[i]->object_instance,data);
		}
	}
}
