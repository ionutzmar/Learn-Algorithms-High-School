#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
/*
This program sorts the number from 1 to n respecting your rules (not natural order!). To find out sequence of numbers, you type in
pairs of numbers (i, j) where the number i will be before j in the answer.
Eg:
Input: 4 , (3,4), (4,3), (1,2), (3,1)
Output: 3142 and 3412

*/
int counter = 0;//how many times it looped

struct node
{
    int info;
    node *nextAddr;
};
void addNodeFirst(node *&v, int value)
{
    node *c = new node;
    c->info = value;
    c->nextAddr = v;
    v = c;
}
void printList(node *nod)
{
    while(nod)
    {
        cout << nod->info << "\n";
        nod = nod->nextAddr;
    }
}

void printVector(int **ans)
{
    for(int i = 0; i < counter; i++)
    {
        int indique = 0;
        while(ans[i][indique] != -1)
        {
            cout << ans[i][indique] << " ";
            indique++;
        }
    }
    cout << "\n";
}

void printAnswer(int **ans, int **indices, int numRep)
{

    //
    // for(int i = pos; i < counter; i++)
    // {
    //     if(ans[i][1] == -1)
    //         cout << a[i] << " ";
    //     else
    //
    //
    // }
    // for(int i = pos; i < counter; i++)
    // {
    //     if(ans[i][1] != -1)
    //     {
    //         int indique = 0;
    //         while(ans[i][indique] != -1)
    //             indique++;
    //         indique -= 1;
    //         do {
    //             printVector(ans);
    //             printAnswer(ans, i + 1);
    //         } while(next_permutation(ans[i], ans[i] + indique));
    //         break;
    //     }
    // }
}


int main(int argc, char const *argv[])
{
    ifstream f("data.in");
    cout << "Type in the number of numbers: ";
    int p, i, n;
    //cin >> n;
    f >> n;
    cout << n;
    cout << "\nNow give the number of pairs: ";
    //cin >> p;
    f >> p;
    cout << p << "\n";
    int *contor = new int[n];
    int **alternative = new int*[n];
    for (i = 0; i <= n; i++)
        alternative[i] = new int;
    node **adr = new node*[n];
    for(i = 0; i < n; i++)
        contor[i] = 0;
    for (i = 0; i < p; i++)
    {
        int a, b;
        cout << "Type now the " << i + 1 << " pair: ";
        f >> a >> b;
        cout << a << " " << b;
        //cin >> a >> b;
        cout << "\n";
        addNodeFirst(adr[a - 1], b);
        contor[b - 1] += 1;
    }
    //solve(contor, adr);

    int status = 1; //it is 0 when the algorithm ends
    int *reminder = new int[n];
    while(status)
    {
        status = 0;
        for(int i = 0; i < n; i++)
        {
            if (contor[i] == 0)
            {
                reminder[status] = i;
                status++;
                //cout << status << "\n";
            }
        }

        for (int i = 0; i < status; i++)
        {
            contor[reminder[i]] = -1;
            alternative[counter][i] = reminder[i] + 1;
            while(adr[reminder[i]])
            {
                contor[adr[reminder[i]]->info - 1] -= 1;
                adr[reminder[i]] = adr[reminder[i]]->nextAddr;
            }
        }
        alternative[counter][status] = -1;
        counter++;
    }

    bool corect = true;
    for (int i = 0; i < n; i++)
    {
        if (contor[i] != -1)
        {
            cout << "Data is incorrect!";
            corect = false;
            break;
        }
    }
    int **indices = new int*[n];  //positiona and number
    for (int i = 0; i < n; i++)
        indices[i] = new int[2];
    int numRep = 0;
    if (corect)
    {
        for(int i = 0; i < counter; i++)
        {
            int indique = 0;
            while(alternative[i][indique] != -1)
                indique++;
            if (indique > 0)
            {
                indices[numRep][0] = i;
                indices[numRep][1] = indique;
                numRep++;
            }
            sort(alternative[i], alternative[i] + indique);
        }
        printAnswer(alternative, indices, numRep);
    }
    return 0;
}
