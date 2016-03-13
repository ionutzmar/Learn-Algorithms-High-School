#include <iostream>

using namespace std;

int fibo(int k)
{
    if(k == 1)
        return 1;
    else if(k == 2)
        return 1;
    else
        return fibo(k - 1) + fibo(k - 2);
}
int main()
{
    int termen;
    cout << "Type in the number of the termen you want to know: ";
    cin >> termen;
    //cout << fibo(30);
    int a = 1, b = 1, c;
    //cin >> n;
    for(int i = 3; i <= termen; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c;
    return 0;
}
