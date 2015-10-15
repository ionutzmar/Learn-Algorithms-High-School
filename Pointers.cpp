#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	struct elev
	{
		char nume[20], prenume[20];
		float medie;
		int varsta;
	};
	elev a;
	cin >> a.nume;
	a.varsta = 17;
	cout << "Nume: " << a.nume << "\nVarsta: " << a.varsta; 
	return 0;
}