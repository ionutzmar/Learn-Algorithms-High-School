#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int *p, n;
	n = 5;
	p = &n;
	cout << "&n: " << &n << "\np: " << p << "\n*p: " << *p << "\n&p: " << &p << endl;
	cout << "Size of int: " << sizeof(int);
	int *a, b;
	b = 5;
	a = &b;
	cout << "\n&b: " << &b << "\na: " << a << "\n*a: " << *a << "\n&a: " << &a << endl;
	int q = 7, *adr = &q;
	cout << *adr;
	return 0;
}