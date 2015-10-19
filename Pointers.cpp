#include <iostream>
#include "utilities.h"

using namespace std;

int* sum(int a, int b)
{
	int *s = new int;
	*s = a + b;
	return s;
}

int main(int argc, char* argv[])
{
	float (*a)[3][3][3], b[4][3][3][3];

	b[3][2][2][1] = 1111;
	
	a = b;
	cout << a[3][2][2][1] <<  endl;

	
	cout << *sum(2,3);

	return 0; 
}

