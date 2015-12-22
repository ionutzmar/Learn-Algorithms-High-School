#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {

    ifstream f("minesweeper2.in");
    ostream g("minesweeper2.out");
    int n;
    f >> n;
    int *v = new int[n];
    int *r = new int[n];
    for (size_t i = 0; i < n; i++)
        r[i] = -1;

    for (int i = 0; i < n; i++)
    {
        f >> v[i];
        cout << v[i];
    }
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 3)
        {
            r[i] = 1;
            if (i > 0)
                r[i - 1] = 1;
            if(i < n - 1)
                r[i + 1] = 1;
        }
        if (v[i] == 2)
        {
            if (i > 0)
                r[i - 1] = 1;
            if(i < n - 1)
                r[i + 1] = 1;
        }
    }
    f.close();
    g.close();
    return 0;
}
