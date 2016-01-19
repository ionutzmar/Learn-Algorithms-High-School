#include <iostream>

using namespace std;
int n, p, *sol, count;

bool valide(int k)
{
    for(int i = 1; i < k; i++)
        if(sol[i] == sol[k])
            return false;
    return true;
}
void back(int k)
{
    if(k == p + 1)
    {
        for (int i = 1; i <= p; i++)
                cout << sol[i];
        cout << "\n";
        count++;
    }
    else
    {
        sol[k] = 0;
        while(sol[k] < n)
        {
            sol[k]++;
            if(valide(k))
                back(k + 1);
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> n >> p;
    if(p > n)
        return -1;
    sol = new int[p + 1];
    back(1);
    cout << "count: " << count << "\n";
    return 0;
}
