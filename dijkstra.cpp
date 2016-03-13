#include <iostream>
#include <fstream>

/*In dijkstra.in on the first line are the number of cities and the city you are in.
On the following lines are two cities and the cost between them:
i j k = to get from i to j you have to pay $k. */

using namespace std;

int m[50][50], s[50], s2[50], p2[50], coada[50], n, tr[50], o, d[50], vs[50], t[50];
int pinfinit = (((unsigned int) - 1) & ~(1 << 31)) / 17;

void printm()//print the matrix
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << m[i][j] << " ";
        cout << "\n";

    }
}

void printdr(int nod)//print the path
{
    if(t[nod] != 0)
    {
        printdr(t[nod]);
        cout << t[nod] << " ";
    }
}

void df(int nod) //depth first
{
    for(int i = 1; i <= n; i++)
    {
        if(m[nod][i] != pinfinit && i != nod && s2[i] == 0)
        {
            tr[i] = nod;
            s2[i] = 1;
            //cout << i << " ";
            df(i);
        }

    }
}
void ds(int nod) // depth first in reverse
{
    for(int i = 1; i <= n; i++)
    {
        if(m[i][nod] != pinfinit && i != nod && p2[i] == 0)
        {
            p2[i] = 1;
            ds(i);
        }
    }
}

int main()
{
    int i, k ,j, ic = 1, sc = 1, poz = 0, minim;
    ifstream f("data.in");
    f >> n;
    f >> o;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if(i != j)
                m[i][j] = pinfinit;

    while(f >> i >> j >> k)
    {
        //cout << i << " " << j << " " << k << "\n";
        m[i][j] = k;
    }
    f.close();
    //printm();
    cout << "From the city number " << o << " you can drive to the following cities\n";
    coada[ic] = o;
    s[o] = 1;
    while(ic <= sc)
    {
        for(i = 1; i <= n; i++)
        {
            if(m[coada[ic]][i] != pinfinit && coada[ic] != i && s[i] == 0)
            {
                s[i] = 1;
                sc++;
                coada[sc] = i;
            }
        }
        ic++;
    }
    for(i = 1; i <= n; i++)
        if(s[i] == 1)
            cout << i << " ";
    cout << endl;
    //printm();
    s2[o] = 1;
    df(o);
    ds(o);
    cout << endl << "You can go and return from the following cities:\n";

    for(i = 1; i <= n; i++)
        if (s2[i] == 1 && p2[i] == 1)
            cout << i << " ";
    //printdr(15);

    //Beginning of Dijkstra algorithm
    vs[o] = 1;
    for(i = 1; i <= n; i++)
    {
        d[i] = m[o][i];
        if(d[i] < pinfinit && i != o)
            t[i] = o;
    }
    for(i = 1; i < n; i++)
    {
        minim = pinfinit;
        for(j = 1; j <= n; j++)
        {
            //cout << j << " " << n << "\n";
            if(minim > d[j] && vs[j] == 0)
            {
                minim = d[j];
                poz = j;
            }
        }
        vs[poz] = 1;
        for(j = 1; j <= n; j++)
        {
            if(d[j] > d[poz] + m[poz][j] && vs[j] == 0)
            {
                d[j] = d[poz] + m[poz][j];
                t[j] = poz;
            }
        }
    }
    cout << "\n\nThe shortest distance from " << o << " to the rest of the cities is:\n";
    for(i = 1; i <= n; i++)
        cout << d[i] << " ";
    int destination;
    cout << "\n\nType a city to find out the shortest path to it:";
    cin >> destination;
    printdr(destination);
    cout << endl;
    //Ending of Dijkstra algorithm

    return 0;
}
