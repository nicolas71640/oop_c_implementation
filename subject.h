
#ifndef SUBJECT_DEF
#define SUBJECT_DEF

#include "stdint.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "observer.h"

/*PREPROCESSOR DIRECTIVES*/
#define MAX_SUBJECTS_NUMBER	10
#define NUMBER_OF_OBSERVERS_MAX 10



/*STRUCTURES AND ENUMERATIONS*/
typedef struct Subject Subject;
struct Subject{
	/*Attributes*/
	Observer (*observers[NUMBER_OF_OBSERVERS_MAX]);
	
	/*Public Methods*/
	bool (*addObserver)(Subject * const self, Observer *observer);
	bool (*deleteObserver)(Subject* const self, Observer *observer);
	void (*cleanObservers)(Subject * const self);
	void (*notifyObservers)(Subject * const self,void *data);
};

/*PROTOTYPES*/
Subject *Subject_Create(void);
bool Subject_addObserver(Subject * const self, Observer *observer);
bool Subject_deleteObserver(Subject * const self, Observer *observer);
void Subject_cleanObservers(Subject * const self);
void Subject_notifyObservers(Subject * const self,void *data);

#endif
