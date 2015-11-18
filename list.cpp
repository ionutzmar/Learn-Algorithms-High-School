#include <iostream>

using namespace std;


struct node
{
	int info;
	node *next_adr;
};

node *v;
int counter = 1;

void addNodeLast(node* v,int value)  //add a node with info = value at the end of the list v
{
	if (v -> next_adr)
	{
		addNodeLast(v -> next_adr, value);
	}
	else
	{
		node* c = new node;
		v -> next_adr = c;
		c -> next_adr = 0;
		c -> info = value;
	}
}
void addNode(node* l, int value, int p)  //and a node to the list v at the position p. If p == -1 the node will be added at the end of the list
{
	if (p == 0)
	{
		node* c = new node;
		c -> info = value;
		c -> next_adr = l;
		v = c;

	}
	else if (p > 0)
	{
		if(counter == p)
		{
			node* c = new node;
			c -> info = value;
			c -> next_adr = l -> next_adr;
			l -> next_adr = c;
			counter = 1;
			return;
		}
		else
		{
			counter++;
			if (l -> next_adr)
				addNode(l -> next_adr, value, p);
			else
				counter = 1;
			return;
		}
	}
	else if(p == -1)
	{
		addNodeLast(v, value);
	}
}

void inverseList(node* v)  //inverses the list v
{

}

node* createList()
{
	node* c;
	int nr;
	cout << "Number: "; cin >> nr;
	if(nr)
	{
		c = new node;
		c -> next_adr = createList();
		c -> info = nr;
		return c;
	}
	else
		return 0;
}

void show(node* v)  //It shows the list in the right order.
{
	node *c = v;
	while(c)
	{
		cout << c -> info << endl;
		c = c -> next_adr;
	}
}

void showInv(node* v) //It shows the list in the invers order without the first element of the list.
{
	if(v -> next_adr)
	{
		v = v -> next_adr;
		showInv(v);
		cout << v-> info << endl;
	}
}

int main(int argc, char const *argv[])
{
	v = createList();
	show(v);

	int pos, val;
	while(1)
	{
		cin >> val >> pos;
		cout << "\n";
		addNode(v, val, pos);
		show(v);
	}
	
	return 0;
}