#include <iostream>
#include <typeinfo>

int main(void)
{
	double d = 20.05;
	double * pDouble = &d;
	//int * pInt = &d; throws error

	std::cout << "\n";
	std::cout << "Variable\tValue\t\t\tType" << "\n";
	std::cout << "\n";
	std::cout << "d:\t\t" << d << "\t\t\t" << typeid(d).name() << "\n";
	std::cout << "&d:\t\t" << &d << "\t\t" << typeid(&d).name() << "\n";
	std::cout << "\n";
	std::cout << "pDouble:\t" << pDouble << "\t\t" << typeid(pDouble).name() << "\n";
	std::cout << "*pDouble:\t" << *pDouble << "\t\t\t" << typeid(*pDouble).name() << "\n";
	std::cout << "&pDouble:\t" << &pDouble << "\t\t" << typeid(&pDouble).name() << "\n";
	/*std::cout << "\n";
	std::cout << "d type:\t\t" << typeid(d).name() << "\n";
	std::cout << "&d type:\t" << typeid(&d).name() << "\n";
	std::cout << "pDouble type:\t" << typeid(pDouble).name() << "\n";
	std::cout << "*pDouble type:\t" << typeid(*pDouble).name() << "\n";
	std::cout << "&pDouble type:\t" << typeid(&pDouble).name() << "\n";*/
	std::cout << "\n" << std::flush;

	return 0;
}
