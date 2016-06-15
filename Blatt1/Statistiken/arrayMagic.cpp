#include "arrayMagic.h"

void bubbleSort(double array[], const short int aSize) {
	short int i, j;
	bool swapped = true;
	
	for(i = 0; (i < aSize) && swapped; i++) {
		swapped = false;
		for(j = 0; j < (aSize-1); j++) {
			if(array[j+1] < array[j]) {
				array[j] += array[j+1];
				array[j+1] = array[j] - array[j+1];
				array[j] -= array[j+1];
				swapped = true;
			}
		}
	}
}

double getMedian(double array[], const short int aSize) {
	return aSize % 2 == 0 ? (array[aSize/2] + array[aSize/2 + 1])/2 : array[(aSize+1)/2];
}

short int getMedianIndex(double array[], const short int aSize) {
	return aSize % 2 == 0 ? aSize/2 : (aSize+1)/2;
}
