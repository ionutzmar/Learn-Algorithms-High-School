#include <iostream>

using namespace std;


struct node
{
	int info;
	node *next_adr;
};

node *v;

node* addNode()
{
	node* c;
	int nr;
	cout << "Number: "; cin >> nr;
	if(nr)
	{
		c = new node;
		c -> next_adr = addNode();
		c -> info = nr;
		return c;
	}
	else
		return 0;
}

void show(node* v)
{
	node *c = v;
	while(c)
	{
		cout << c -> info << endl;
		c = c -> next_adr;
	}
}

int main(int argc, char const *argv[])
{
	v = addNode();
	show(v);
	return 0;
}