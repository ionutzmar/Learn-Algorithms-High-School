#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char sir[11];
	cin.get(sir, 10, '.');
	cout << sir << endl;
	cin.get();
	cin.get(sir, 10, '.');
	cout << sir << endl;


	char sir1[10] = "foaie";
	char sir2[10] = "VERDEEEEE";
	cout << (sir1 > sir2);
	return 0;
}