#include<iostream>

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
	
	new_node->next =  *head;
	if(*head!=NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
	
	
}

void reverse(Node** head)
{
	Node* curr = *head;
	Node* prev = NULL;
	Node* temp = NULL;
	
	
	while(curr!=NULL)
	{
		temp = curr->next;
		curr->next = prev;
		prev =  curr;
		curr = temp;
		
	}
	
	*head = prev;
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
	display(head);
	reverse(&head);
	display(head);
}
