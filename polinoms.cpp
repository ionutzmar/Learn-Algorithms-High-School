#include <iostream>
#include <fstream>
#include "utilities.h"

using namespace std;

struct node
{
    int grad;
    float coef;
    node* next_addr;
};

void addNodeLast(node* &v, node* &sf, int gr, float coef)
{
    node *c;
    c = new node;
    c->grad = gr;
    c->coef = coef;
    c->next_addr = 0;
    if(v == 0)
        v = sf = c;
    else
    {
        sf->next_addr = c;
        sf = c;
    }
}
void printList(node* v)
{
    node *c = v;
	while(c)
	{
		cout << c->grad << " " << c->coef << "\n";
		c = c -> next_addr;
	}
    // cout << v->grad << " " << v->coef << "\n";
    // if(v->next_addr)
    //     printList(v->next_addr);
}
node* createPolinom(void)
{
    ifstream f("data.in");
    int noMonoms;
    f >> noMonoms;

    int* grades = new int[noMonoms];
    float* coefficients = new float[noMonoms];
    for(int i = 0; i < noMonoms; i++)
    {
        f >> grades[i];
        f >> coefficients[i];
    }

    quickSortForPolinoms(grades, coefficients, 0, noMonoms - 1);

    node *v = 0, *sf;
    for(int i = 0; i < noMonoms; i++)
        addNodeLast(v, sf, grades[i], coefficients[i]);

    delete grades;
    delete coefficients;
    return v;
}

void deleteList(node* v)
{
    node *c = v;
    while(v)
    {
        v = v->next_addr;
        delete c;
        c = v;
    }
}

int main(int argc, char const *argv[])
{
    node *v = createPolinom();
    printList(v);
    return 0;
}
