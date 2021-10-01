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
	new_node->next = *head;
	
	if(*head!=NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
	
}
void Pair(Node* head, int x)
{
	Node* first = head;
	Node* last  = head;
	
	while(last->next!=NULL)
	{
		last = last->next;
	}
	bool found  = false;
	
	while(first!=last && last->next!=first)
	{
		if((first->data+last->data) ==x)
		{
			found = true;
			cout<<"("<<first->data<<","<<last->data<<")"<<endl;
			
			
			first = first->next;
			last = last->prev; 
		}
		else{
			if((first->data+last->data) <x)
			{
				first =  first->next;
			}
			else{
				last = last->prev;
			}
		}
		
		
	}
	 if (found == false)
        cout << "No pair found";

	
	
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
	
	
	push(&head,9);
	push(&head,8);
	push(&head,6);
	push(&head,5);
	push(&head,1);
	push(&head,2);
	push(&head,1);
	print(head);
	Pair(head,7);
	
//	1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
//	x  = 7;
    
}
