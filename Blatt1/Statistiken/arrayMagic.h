#pragma once

// gets reference to array and sorts it
void bubbleSort(double array[], const short int aSize);

// takes sorted array and returns the median value
double getMedian(double array[], const short int aSize);

// takes sorted array and returns index of last element <= median
short int getMedianIndex(double array[], const short int aSize);

