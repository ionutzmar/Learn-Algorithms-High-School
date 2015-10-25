#include <iostream>
#include "utilities.h"

using namespace std;


int main(int argc, char* argv[])
{
	int n;
	float *v, s = 0;

	cin >> n;

	v = new float[n];

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		s += v[i];
	}
	cout << s / n;

	return 0; 
}

