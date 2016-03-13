#include <iostream>
#include <fstream>

using namespace std;

int t[50][50], c[50][50], d[50][50];

int main()
{
    int i, j, n;
    ifstream f("triangle.in");
    f >> n;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= i; j++)
            f >> t[i][j];
    f.close();
    for(i = 1; i <= n; i++)
        c[n][i] = t[n][i];
    for(i = n - 1; i >= 1; i--)
    {
        for(j = 1; j <= i; j++)
        {
            if(c[i + 1][j] < c[i + 1][j + 1])
            {
                c[i][j] = t[i][j] + c[i + 1][j + 1];
                d[i][j] = j + 1;
            }
            else
            {
                c[i][j] = t[i][j] + c[i + 1][j];
                d[i][j] = j;
            }
        }
    }
    j = i = 1;

    cout << "The highest sum is: " << c[1][1] << "\n";
    while(i <= n)
    {
        if(i != n)
            cout << t[i][j] << " + ";
        else
            cout << t[i][j] << " = " << c[1][1];
        j = d[i][j];
        i++;
    }


    return 0;
}
