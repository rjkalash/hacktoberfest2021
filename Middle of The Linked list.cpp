#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
};
void push(Node**head, int val)
{
	
	Node* new_node = new Node();
	new_node->data = val;
	new_node->next = *head;
	*head = new_node;
}
int lenght(Node* head)
{
	Node* tem = head;
	int count =0;
	while(tem!=NULL)
	{
//		cout<<"1";
		count++;
		
		tem = tem->next;
		
	}
	return count;
	
	
	
}
void dp(Node* head)
{
	Node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL\n";
	int mid = lenght(head);
	for(int i=0;i<mid/2;i++)
	{
		head = head->next;
	}
	cout<<head->data;
}

int main()
{
	Node* head = NULL;
	push(&head,9);
	push(&head,4);
	push(&head,6);
	push(&head,5);
	push(&head,3);
	push(&head,2);
	dp(head);
}
