#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Linkedlist{
	ll data;
	struct Linkedlist *next;
};

typedef struct Linkedlist *node;

int main()
{
	ll n,i,x,pos;
	cin>>n;
	node head,temp,p;
	head=NULL;		//assigning nothing to head node
	head=(node)malloc(sizeof(struct Linkedlist));			//head is just a fictious cell, which is created to get the starting cursor of the list
	temp=head;			//storing the head of list in a temp variable to create the list
	for(i=0;i<n;i++)
	{
		cin>>x;
		p=NULL;		//assigning nothing to node p;
		p=(node)malloc(sizeof(struct Linkedlist));
		p->data=x;
		temp->next=p;		//assigning next pointer of head as p
		temp=temp->next;
	}
	temp->next=NULL;
	// we have stored the list succesfully, now printing the list
	head=head->next;		//coming to first node
	while(head!=NULL)		//output the created list
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
	return 0;
}
