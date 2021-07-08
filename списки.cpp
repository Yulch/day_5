#include <iostream>
using namespace std; 

struct Node {
  int val;
  Node* next = NULL;
};


void init(Node* node) 
{
	node->val = 0;
	node->next = NULL;
}


void show(Node* head) 
{
	Node* a = head;
	while(a->next !=NULL)
	{
		cout << a->val << " ";
		temp = a->next;
	}
}


void pushNode(Node* head,Node* node) 
{
	Node* a = head;
	while(a->next != NULL) 
	a = a->next;
	a->next = new Node;
	a->val = node->val;
} 



void initList(Node* head, int size, int val)  {

}


void copyMas(Node* source, Node* dest) 
{
    	while (source->next != NULL && dest->next != NULL) 
	{
        	dest->val = source->val;
        	dest = dest->next;
        	source = source->next;
    	}
}
  


int compareMas(Node* source, Node* dest) {
  return 0;
}



void deleteList(Node* head,int n) {

}



void rShiftList(Node* head,int n) {

}




void lShiftList(Node* head,int n) {

}



void lRoundShiftMas(Node* head,int n, int size) {

}



int averageList(Node* head, int size) {
  return 0;
}




int skoFromList(Node* head, int size) {
  return 0;
}


int testSkoFromList() {
  return -1;
}


bool TestInit()
{
	Node* head = new Node;
	init(head);
	return (head->val == 0);
}

int testCopyMas() 
{
	Node* source = new Node;
	Node* dest = new Node;
	Node* SourceNode = source, * DestNode = dest;
 	for (int i = 0; i <= 10; i++)
	{
        	pushNode(source, new Node);
        	pushNode(dest, new Node);
        	init(DestNode);
        	SourceNode = SourceNode->next;
        	DestNode = DestNode->next;
    	}
	if (compareMas(source, dest) != 0)
        	return -1;
    	if (compareMas(source, dest) != -1)
        	return -1;
}


    
    
    
