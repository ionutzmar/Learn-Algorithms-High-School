#include <iostream>
#include <fstream>
using namespace std;

/*
In this program is the Prim's algorithm.

This program builds the minimum spanning tree in matrix 'a' from an undirected graph 'm'.
It also prints the T vector.*/

int m[50][50], s[50], a[50][50], ss[50], t[50], n;
int pinfinit = ((unsigned int) - 1) & ~(1 << 31);
int beginning;

void df(int nod)
{
    for(int i = 1; i <= n; i++)
        if(a[nod][i] != 0 && a[nod][i] != pinfinit && ss[i] == 0)
        {
            ss[i] = 1;
            t[i] = nod;
            df(i);
        }
}

int main()
{
    int j, k, i;
    ifstream f("prim.in");
    f >> n;
    for(i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j)
                m[i][j] = pinfinit;
    while(f >> i >> j >> k)
    {
        m[i][j] = k;
        m[j][i] = k;
    }

    cout << "Type in the node you want to start with: ";
    cin >> beginning;
    s[beginning] = 1;
    for(k = 1; k < n; k++)
    {
        int lin;
        int col;
        int min = pinfinit;
        for(i = 1; i <= n; i++)
        {
            if(s[i] == 0)
                continue;
            for(j = 1; j <= n; j++)
            {
                if(s[j] == 0 && i != j && min > m[i][j])
                {
                    min = m[i][j];
                    col = j;
                    lin = i;
                }
            }
        }
        if (min != pinfinit)
            {
                s[col] = 1;
                a[lin][col] = a[col][lin] = min;
            }
    }

    ss[beginning] = 1;
    df(beginning);
    for(i = 1; i <= n; i++)
        cout << t[i] << " ";
    //for(i = 1; i <= n; i++)
    //{
    //    for (j = 1; j <= n; j++)
    //        cout << a[i][j] << " ";
    //    cout << "\n";
    //}

    return 0;
}
