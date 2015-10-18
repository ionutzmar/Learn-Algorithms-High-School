#include <iostream>
#include "utilities.h"

using namespace std;

int main(int argc, char* argv[])
{
	float *a = new float[3];
	0[a] = 1;
	1[a] = 2;
	a[2] = 3;
	cout << a[0] << " " << a[1] << " " << a[2] << endl;
	delete a;
	cout << a[0] << " " << a[1] << " " << a[2] << endl;
	a = new float[3];
	0[a] = 1;
	1[a] = 2;
	a[2] = 3;
	cout << a[0] << " " << a[1] << " " << a[2] << endl;
	delete a;
	cout << a[0] << " " << a[1] << " " << a[2];
	return 0;
}

