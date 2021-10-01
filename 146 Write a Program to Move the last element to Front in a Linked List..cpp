#include <bits/stdc++.h>
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




void last_in_fron(Node** head)
{

	
	Node* prev = NULL;
	Node* last = *head;
	
	while(last->next!=NULL)
		{
			prev = last;
			last = last->next;
		} 
		
		prev->next= NULL;
		last->next = *head;
	
		*head = last;
                    
          	
}



void print(Node* head)
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
	
	
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	
	print(head);
	last_in_fron(&head);
	print(head);
	
}
