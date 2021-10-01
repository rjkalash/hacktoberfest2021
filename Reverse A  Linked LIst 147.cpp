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


void Reverse(Node **head)
{
	Node* temp = NULL;
	Node* prev = NULL;
	Node* current = *head;
	
	while(current!=NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	
	*head = prev;
}



void print(Node* head)
{
	Reverse(&head);
	
	Node* temp = head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
		
	}
	cout<<"NULL"<<endl;
	
	
}

int main()
{
	
	
	Node* head = NULL;
	
	
	push(&head,5);
	push(&head,6);
	push(&head,5);
	push(&head,2);
	push(&head,3);
	push(&head,2);
	push(&head,5);
	print(head);
}
