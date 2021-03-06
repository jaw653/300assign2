/**
 * Author: Jacob Wachs
 * Institution: The University of Alabama
 * Course: CS 300 Operating Systems
 * Date: 9/25/2018
 */

// Linux: uses bitmap value 0 at position i indicates pid of value i is available
// bit in bitmap: process_currently_in_use - t/F

// pthread_t thread 0;  -  thread reference variable
// pthread_create(&thread0, NULL(extra attributes), entryFC, paramsForEntryFC);    -  creates new thread
// pthread_join(thread0, NULL);      -  joins work from threads
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MIN_PID 300
#define MAX_PID 5000


struct PID {
	int pid;
	unsigned int pid_in_use;
};
typedef struct PID PID;

PID **bitmap;


int allocate_map(void);		// Creates and initializes a data structure for representing pids; returns 1 if successful, else 0
int allocate_pid(void);		// Allocates and returns a pid; return 1 if unable to allocate (all possible are in use)
void release_pid(int);		// Releases a pid


int main(void) {

	return 0;
}

int allocate_map(void) {
	bitmap = malloc(sizeof(PID) * 4700);

	int i;
	for (i = 0; i <= 4700; i++) {
		if ( !(bitmap[i] = malloc(sizeof(PID))) )
			return 0;
	}

	return 1;
}

int allocate_pid(void) {
	int i;
	for (i = 0; i <= 4700; i++) {
		if (!bitmap[i]->pid_in_use) {
			bitmap[i]->pid_in_use = 1;
			bitmap[i]->pid_in_use = i + 300;
			return (i + 300);
		}
	}

	return 1;
}

void release_pid(int pid) {
	int index = pid - 300;
	bitmap[index]->pid_in_use = 0;
}