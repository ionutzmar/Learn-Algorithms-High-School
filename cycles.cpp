#include <iostream>
#include <fstream>

using namespace std;

/*
The input data is an undirected graph.
This program print all the elementary cycles if any. It also prints the T vector, which indicates how the nodes are connected. */
int m[50][50], found = 0, s[50], st, t[50], n;

void cycle(int nod)
{
    cout << st << " ";
    while(nod != st)
    {
        cout << nod << " ";
        nod = t[nod];
    }
    cout << st << "\n";
}
void df(int nod)
{
    s[nod] = 1;
    for(int i = 1; i <= n; i++)
        if(m[nod][i] == 1)
        {
            m[i][nod] = 0;
            if(s[i] == 0)
            {
                t[i] = nod;
                //s[i] = 1;
                df(i);
            }
            else
            {
                found = 1;
                st = i;
                cycle(nod);

            }
        }
}

int main()
{
    int i, j;
    ifstream f("data.in");
    f >> n;
    while(f >> i >> j)
    {
        m[i][j] = 1;
        m[j][i] = 1;
    }

    f.close();
    df(1);
    if(!found)
        cout << "There are no cycles...";
    cout << "\nHere is the T vector:\n";
    for(i = 1; i <= n; i++)
        cout << t[i] << " ";
    return 0;
}
