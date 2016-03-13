#include <iostream>
#include <fstream>

using namespace std;

int m[50][50], n;
void printMatr(int matr[][50], int dimension)
{
    for(int i = 1; i <= dimension; i++)
    {
        for(int j = 1; j <= dimension; j++)
            cout << matr[i][j] << " ";
        cout << "\n";
    }

}

void royFloyd() //now the graph contains the minimum cost between two cities
{
    for(int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (m[j][i] > m[j][k] + m[k][i])
                    m[j][i] = m[j][k] + m[k][i];
}

void divide(int i, int j) //Divide et impera method for showing the path
{
    int k = 1, found = 0;
    while(k <= n && !found)
    {
        if(m[i][j] == m[i][k] + m[k][j] && i != k && j != k)
        {
            found = 1;
            divide(i, k);
            cout << k << " ";
            divide(k, j);
        }
        k++;
    }
}
int main()
{
    ifstream f("royFloyd.in");
    int i, j, k, a, b;
    int pinfinit = (((unsigned int) - 1) & ~(1 << 31)) / 2;
    f >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                m[i][i] = 0;
            else
                m[i][j] = pinfinit;
        }
    }
    while(f >> i >> j >> k)
        m[i][j] = k;

    f.close();
    royFloyd();
    printMatr(m, n);
    cout << "Type in two cities to find out the path between them: ";
    cin >> a >> b;
    if(m[a][b] < pinfinit)
    {
        cout << a << " ";
        divide(a, b);
        cout << b;
    }

    else
        cout << "There is no route from a to b :(";
    return 0;
}
