#include <iostream>

/* Shifting the address a pointer holds
 *
 * int is 4 bytes, pointer 8 bytes, so long int
 * must be used.
 */

int main(void)
{
	int d = 22;
	long int address = 0;
	int * p;

	std::cout << "\n";
	std::cout << "&d:   " << &d << "\n";
	
	address = reinterpret_cast<long int>(&d);

	p = reinterpret_cast<int*>(address+8);

	std::cout << "p:   " << p << "\n";
	std::cout << "*p:  " << *p << "\n" << std::flush;

	return 0;
}
