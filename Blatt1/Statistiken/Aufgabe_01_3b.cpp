#include <iostream>
#include "arrayMagic.h"

using namespace std;

int main(void)
{
	double a[10] = {6.20, 33.77, 51.32, 95.11, 11.78, 35.34, 85.18, 89.00, 37.14, 24.02};
	double sum = 0;
	//double median = 0;
	short int medianIndex = 0;
	const short int aSize = sizeof(a)/sizeof(*a);

	bubbleSort(a, aSize);

	//median = getMedian(a, aSize);
	medianIndex = getMedianIndex(a, aSize);

	//for(short int i = 0; a[i] <= median; i++)
	//	sum += a[i];
	// careful! This won't work if the elements used for computing the median
	// for even arrays are equal
	for(int i = 0; i <= medianIndex; i++)
		sum += a[i];

	cout << "sum: " << sum << endl;

	return 0;
}
