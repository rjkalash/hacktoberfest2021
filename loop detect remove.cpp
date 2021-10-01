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

void cycle(Node* head, int val)
{
	
	Node* temp = head;
	Node* start;
	int count =1;
	while(temp->next!=NULL)
	{
		if(count==val)
		{
			start = temp;
		
		}
		temp = temp->next;
		count++;
	}
	
	temp->next = start;
	
}

bool CheckCyle(Node* head)
{
	Node* slow=head;
	Node* fast=head;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(fast==slow)
		{
			return true;
		}
	}
	return false;
}

void removCycle(Node* head)
{
	Node* slow = head;
	Node* fast = head;
	
	do{
		
		
		slow = slow->next;
		fast = fast->next->next;
	}while(slow!=fast);
	
	fast = head;
	while(slow->next!=fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	
	slow->next = NULL;
	
	
	
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
	
	
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	
	display(head);
	cycle(head, 3);

	cout<<CheckCyle(head)<<endl;
	removCycle(head);
	cout<<CheckCyle(head)<<endl;
	display(head);
	
	
	
	
	
}
