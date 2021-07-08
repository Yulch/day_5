#include <iostream>
using namespace std;

class Node
{
	int field;
	class Node* ptr;
	friend class List;
};

class List
{
	Node* head;
	int count = 0;
	Node* Prev(Node*); 
public:
	List() { head = NULL; } 
	int getCount() { return count; } 
	bool isEmpty() { return head == NULL; } 
	int getValue(Node* p) { return p->field; } 
	void setValue(Node* p, int val) { p->field = val; } 
	Node* getFirst() { return head; } 
	Node* getLast();			
	void Clear();				
	Node* Next(Node*);			
	Node* Add(int, Node*);		
	Node* Delete(Node*);		
	void Print();				
	void Swap(Node*, Node*);	
};

Node* List::Add(int num, Node* node = NULL)
{
	Node* elem = new Node();
	elem->field = num;
	count++;
	if (node == NULL) 
	{
		if (head == NULL) {
			elem->ptr = NULL;
			head = elem;
		}
		else {
			elem->ptr = head;
			head = elem;
		}
		return elem;
	}
	elem->ptr = node->ptr; 
	node->ptr = elem;
	return elem;
}

Node* List::Delete(Node* node)
{
	if (node == NULL) { return NULL; } 
	count--;
	if (node == head)	
	{
		head = node->ptr;
		delete node;
		return head;
	}
	Node* prev = Prev(node); 
	prev->ptr = node->ptr;
	delete node;
	return prev;
}

void List::Print()
{
	if (isEmpty()) { return; }
	Node* p = head;
	do {
		cout << getValue(p) << " ";
		p = Next(p);
	} while (p != NULL);
	cout << endl;
}

void List::Clear()
{
	class Node* p = head;
	if (p == NULL) return;
	do {
		Node* d = p;
		p = Next(p);
		delete d;
	} while (p != NULL);
	count = 0;
	head = NULL;
}

Node* List::getLast()
{
	Node* p = head;
	while (Next(p) != NULL)
		p = Next(p);
	return p;
}

Node* List::Next(Node* node)
{
	if (isEmpty()) return NULL;
	return node->ptr;
}

Node* List::Prev(Node* node)
{
	if (isEmpty()) return NULL;
	if (node == head) return NULL;
	Node* p = head;
	while (p->ptr != node)
		p = p->ptr;
	return p;
}

void List::Swap(Node* node1, Node* node2)
{
	if (node1 == NULL || node2 == NULL) return;
	if (node1 == node2) return;
	if (node2->ptr == node1)
	{
		Node* p = node1;
		node1 = node2;
		node2 = p;
	}
	Node* prev1 = Prev(node1);
	Node* prev2 = Prev(node2);
	Node* next1 = Next(node1);
	Node* next2 = Next(node2);
	if (next1 == node2)
	{
		if (prev1 != NULL)
			prev1->ptr = node2;
		else
			head = node2;
		node2->ptr = node1;
		node1->ptr = next2;
		return;
	}
	if (prev1 != NULL)
		prev1->ptr = node2;
	else
		head = node2;
	if (prev2 != NULL)
		prev2->ptr = node1;
	else
		head = node1;
	node2->ptr = next1;
	node1->ptr = next2;
}
int main()
{
	List list;
	list.Print();
	Node* s = list.getLast();
	for (int i = 0; i < 10; i++) {
		s = list.Add(i, s);
	}
	list.Print();
	cout << "Size:  " << list.getCount() << endl;

	Node* p = list.getFirst();
	do {
		if (list.getValue(p) == 2 or list.getValue(p) == 8)
			p = list.Delete(p);
		else
			p = list.Next(p);
	} while (p != NULL);
	list.Swap(list.getFirst(), list.getLast());
	list.Print();
	cout << "Size: " << list.getCount() << endl;
	return 0;
}
