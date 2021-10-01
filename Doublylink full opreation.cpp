#include <bits/stdc++.h>
using namespace std;


class Node{
	public:
	int data;
	Node* next;
	Node* prev;
	
};

void push(Node** head, int val)
{
	Node* new_node = new Node();
	new_node->data = val;
	new_node->next = *head;
	
	if(*head!=NULL)
	{
		(*head)->prev = new_node;
		
	}
	*head = new_node;
	
}

void after(Node* head, int val)
{
	Node* new_node = new Node();
	
	new_node->data = val;
	
	new_node->next = head->next;
	
	head->next = new_node;
	
	new_node->prev = head;
	
	if(new_node->next!=NULL)
	{
		new_node->next->prev = new_node;
	}
	
}

void last(Node* head, int val)
{
	
	Node* new_node = new Node();
	
	new_node->data = val;
	new_node->next = NULL;
	
	Node* last = head;
	
	while(last->next!=NULL)
	{
		last = last->next;
	}
	
	last->next = new_node;
	new_node->prev = last;	
	
}


void deleAtkey(Node* head, int key)
{
	Node* temp = head;
	
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			return;		
		}
		temp =  temp->next;
	}
	
}

void deleAtpossi(Node* head, int possi)
{
	
	Node* temp =  head;
	
	int count =  0;
	
	while(temp!=NULL)
	{
		count++;
		if(count==possi)
		{
		    temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			return;		
		}
		temp = temp->next;
		
	}
	
	
}


void display(Node* head)
{
	
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
	
		
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	
	display(head);
	
	after(head,02);
	display(head);
	last(head,99);
	display(head);
	deleAtkey(head,4);
	cout<<"After delete at 4 key\n";
	display(head);
	
	deleAtpossi(head,6);
	cout<<"After delete at 6 possi\n";
	display(head);

	
}
