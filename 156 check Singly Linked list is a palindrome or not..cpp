#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	
};

void push(Node** head, int val)
{
	Node* new_node =  new Node();
	new_node->data = val;
	new_node->next = *head;
	*head = new_node;
		
}


bool Check_pali(Node* head)
{
	Node* fast = head;
	Node* slow = head;
	while(fast!=NULL and fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next; 
	}
	
	
	Node* temp = NULL;
	Node* prev = NULL;
	Node* current = slow;
	
	while(current!=NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;	
	}
	fast = head;
	while(prev!=NULL)
	{
		if(fast->data!=prev->data)
		{
			return false;
		}
		fast = fast->next;
		prev = prev->next;
	}
	return true;
}


void print(Node* head)
{
	Node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
		
	}
	cout<<"NULL\n";
	
	
}


int main()
{
	
	
	Node* head = NULL;
	
	
	push(&head,1);
	push(&head,2);
	push(&head,2);
	push(&head,2);
	push(&head,2);
	push(&head,2);
	push(&head,1);
	print(head);
	int check = Check_pali(head);
	cout<<endl<<check;
}

