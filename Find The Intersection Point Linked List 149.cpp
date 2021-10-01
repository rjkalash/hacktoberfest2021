#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void push(Node **head, int val)
{
	Node* new_node = new Node();
	new_node->data = val;
	new_node->next = *head;
	*head = new_node;
	
	
}

Node* Intersection_point(Node* head, Node*head1)
{
	Node* ptr1 = head;
	Node* ptr2 = head1;
	Node* temp = NULL;
	Node* curr = NULL;
	
//	cout<<"j";
	
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->data == ptr2->data)
		{
//			cout<<"j";
			if(temp=NULL)
			{
				
				Node* new_Node = new Node();
				new_Node->data = ptr1->data;
				temp = new_Node;
				curr = new_Node;

				
			}
			else {

				Node* new_Node = new Node();
				new_Node->data = ptr1->data;
				curr->next = new_Node;
				
				curr = curr->next;
				
			}
			
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else {
			if(ptr1->data < ptr2->data)
			{
				ptr1 = ptr1->next;
			}
			else{
				ptr2 = ptr2->next;
			}
		}
		
		
	}
	
	return temp;
	
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
	Node* head1 = NULL;
	Node* head3 = NULL;

	push(&head,6);
	push(&head,5);
	push(&head,2);
	push(&head,0);
	push(&head1,8);
	push(&head1,6);
	push(&head1,4);
	push(&head1,2);
	print(head);
	print(head1);
	
	head3 = Intersection_point(head,head1);
	print(head3);
	
}
