#include <iostream>

using namespace std;

int main(void)
{
	for(int i = 777; i >= 0; i -= 13) 
		if(i % 2 == 0)
			cout << i << endl;

	return 0;
}
