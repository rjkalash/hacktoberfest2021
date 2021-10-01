#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
};

void push(Node** head, int val)

{
	Node* new_node = new Node();
	new_node->data = val;
	
	new_node->next = *head;
	*head = new_node;
}


void circular(Node* head)
{
	Node* temp = head;
	
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}

	temp->next = head;
	
}



void del_IN_cirlular(Node* head, int key)
{
	Node* temp = head;
	Node* prev = NULL;

	while(temp->data!=key)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	delete temp;
	temp = prev->next;
	
	
	
}

void print(Node* head)
{
	Node* temp = head;	
	do {
		cout<<temp->data<<"->";
		temp = temp->next;
	}while(temp!=head);
	cout<<endl;

	
}


int main()
{
	
	
	Node* head = NULL;
	
	
	push(&head,7);
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	circular(head);
	print(head);
    del_IN_cirlular(head,5);
    print(head);
}
