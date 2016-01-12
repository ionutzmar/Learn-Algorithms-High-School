#include <iostream>

using namespace std;

/*This is the solution for the Tower of Hanoi problem. Just type the number of discs that you want
to move from the first rod to the second.*/

void hanoi(int n, int a, int b, int c)//from a to b through c
{
    if(n == 1)
        cout << a << b << "  ";
    else
    {
        hanoi(n - 1, a, c, b);
        cout << a << b << "  ";
        hanoi(n-1, c, b, a);
    }
}
int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    return 0;
}
