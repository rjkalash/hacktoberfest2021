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

void removeDupplicat(Node* head)
{
	Node* temp = head;
	Node* ptr1;
	Node* dubli;
	while(temp!=NULL && temp->next!=NULL)
	
	{
		
		ptr1 = temp;
		
		while(ptr1->next !=NULL)
		{
			if(temp->data == ptr1->next->data)
			{
				dubli = ptr1->next;
				ptr1->next = ptr1->next->next;	
				delete (dubli);
			}
			else {
				ptr1 = ptr1->next;
			}
		}
		temp = temp->next;
	
	}
	
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
	
	
	push(&head,5);
	push(&head,6);
	push(&head,5);
	push(&head,2);
	push(&head,3);
	push(&head,2);
	push(&head,5);
	
	print(head);
	removeDupplicat(head);
	print(head);	
}
