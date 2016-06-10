#include <iostream>

using namespace std;

int main(void)
{
	int i = 777;

	do{ 
		if(i % 2 == 0)
			cout << i << endl;
		i -= 13;
	}while(i >= 0);

	return 0;
}
