#include <iostream>

using namespace std;

int n, *sol;

int abs(int a)
{
    if (a >= 0)
        return a;
    return -a;
}


bool valide(int k)
{
    bool ev = true;
    for(int i = 1; i <= k - 1; i++)
        if (abs(i - k) == abs(sol[k] - sol[i]) || sol[k] == sol[i])
            ev = false; //return false
    return ev;
}

bool successor(int k)
{
    if (sol[k] < n)
    {
        sol[k]++;
        return true;
    }
    return false;
}
void init(int k)
{
    sol[k] = 0;
}
void print(void)
{
    for(int i = 1; i <=n; i++)
        cout << sol[i];
    cout << "\n";
}

bool solution(int k)
{
    return k == n + 1;
}
void back(int k)
{
    if(solution(k))
        print();
    else
    {
        init(k);
        while(successor(k))
            if(valide(k))
                back(k + 1);
    }
}
int main(int argc, char const *argv[])
{
    cout << "n = ";
    cin >> n;
    sol = new int[n + 1];
    back(1);
    return 0;
}
