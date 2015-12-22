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
        //cout << nod->info << "\n";
        nod = nod->nextAddr;
    }
}
void addNodeLast(node* v,int value)  //add a node with info = value at the end of the list v
{
	if (v -> nextAddr)
	{
		addNodeLast(v -> nextAddr, value);
	}
	else
	{
		node* c = new node;
		v -> nextAddr = c;
		c -> nextAddr = 0;
		c -> info = value;
	}
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
    for (i = 0; i < n; i++)
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
    int counter = 0;//how many times it looped
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
                adr[reminder[i]] = adr[reminder[i]] -> nextAddr;
            }
        }
        counter++;
    }

    for (int i = 0; i < n; i++)
        cout << alternative[i][0] << "\n";
    if (n + 1 == counter)
        cout << "Well done!\n";

    return 0;
}
