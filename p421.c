/**
 * Author: Jacob Wachs
 * Institution: The University of Alabama
 * Course: CS 300 Operating Systems
 * Date: 9/25/2018
 */

// passed series of numbers via command line
// create three separate worker threads
// 		t1. determine avg of nums
// 		t2. determine max
// 		t3. determine min
// vars representing avg, min and max are global
// 		worker threads will set these values
// 		parent will output once workers have exited
//
// 		The average value is 82
// 		The minimum value is 72
// 		The maximum value is 95

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *set;
int size;
int avg = 0;
int min = 0;
int max = 0;

void *find_avg(void *);
void *find_min(void *);
void *find_max(void *);


int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Error, not enough command line arguments. Exiting.\n");
		return 0;
	}
	
	size = argc - 1;
	set = malloc(sizeof(int) * size);


	/* Insert all cmdline args into set of nums */
	int i;
	for (i = 1; i <= size; i++)
		set[i-1] = atoi(argv[i]);


	/* Initialize array of threads */
	pthread_t threads[3];

	pthread_create(&threads[0], NULL, (*find_avg), NULL);
	pthread_create(&threads[1], NULL, (*find_min), NULL);
	pthread_create(&threads[2], NULL, (*find_max), NULL);

	for (i = 0; i < 3; i++)
		pthread_join(threads[i], NULL);

	printf("The average value is %d\n", avg);
	printf("The minimum value is %d\n", min);
	printf("The maximum value is %d\n", max);

	return 0;
}

void *find_avg(void *ptr) {
	int i, total = 0;
	for (i = 0; i < size; i++) {
		total += set[i];
	}

	avg = total/size;

	return ptr;
}

void *find_min(void *ptr) {
	int i;
	min = set[0];
	for (i = 1; i < size; i++) {
		if (set[i] < min) {
			min = set[i];
		}
	}

	return ptr;
}

void *find_max(void *ptr) {
	int i;
	max = set[0];
	for (i = 1; i < size; i++) {
		if (set[i] > max) {
			max = set[i];
		}
	}

	return ptr;
}