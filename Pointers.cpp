#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int *a, c;
	float *d, e;
	a = &c;
	d = &e;
	e = 2.5;


	cout << "a: " << a << "\nd: " << d << endl;
	a = (int *)d;
	cout << "a: " << a << "\nd: " << d << endl;
	cout << "*a: " << *a << "\n*d: " << *d << endl;
	cout << "size of float: " << sizeof(float);
	return 0;
}