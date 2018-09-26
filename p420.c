/**
 * Author: Jacob Wachs
 * Institution: The University of Alabama
 * Course: CS 300 Operating Systems
 * Date: 9/25/2018
 */

// Modify to make multithreaded
// Make 100 threads, that will each request PID, sleep for a random period of time, then release PID
// Sleep is accomplished through sleep() fc

// pthread_t thread 0;  -  thread reference variable
// pthread_create(&thread0, NULL(extra attributes), entryFC, paramsForEntryFC);    -  creates new thread
// pthread_join(thread0, NULL);      -  joins work from 

/**
 * Questions:
 *		- Should sleep time actually be random? This could take a really long time...
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

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
void *do_job(void *);


int main(void) {
	if ( !(allocate_map()) ) {
		perror("allocate_map() error. Exiting...\n");
		return 0;
	}

	pthread_t threadArr[100];

	int i;
	for (i = 0; i < 100; i++) {
		pthread_create(&threadArr[i], NULL, (*do_job), NULL);
		//pthread_join(thread, NULL);
	}


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

void *do_job(void *ptr) {
	int pid = allocate_pid();
	printf("pid is: %d\n", pid);
	sleep(rand()%5);
	printf("sleeping...\n");
	release_pid(pid);


	return ptr;
}