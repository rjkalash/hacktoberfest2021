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
	new_node->next =  *head;
	*head = new_node;
	
	
}

Node* Reverse_Kth(Node* head, int K)
{
	Node* temp = NULL;
	Node* prev = NULL;
	Node* current = head;
	int count =0;
	
	while(current!=NULL && count<K)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
		count++;
	}
	if(temp!=NULL)
	{
		head->next = Reverse_Kth(temp,K);
		
	}
	return prev;
	
}




void dips(Node* head)
{
	Node* temp = head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp =  temp->next;
	}
	
	cout<<"NULL"<<endl;
	
	
	
	
}



int main()
{
	
	
	
	Node* head  = NULL;
	
	
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	dips(head);
	head = Reverse_Kth(head,3);
	dips(head);
	
	
	
	
}
