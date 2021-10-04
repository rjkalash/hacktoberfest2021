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
	head=(node)malloc(sizeof(struct Linkedlist));
	temp=head;
	for(i=0;i<n;i++)
	{
		cin>>x;
		p=NULL;		//assigning nothing to node p;
		p=(node)malloc(sizeof(struct Linkedlist));
		p->data=x;
		temp->next=p;			//assigning next pointer of temp as p
		temp=temp->next;
	}
	temp->next=NULL;

	//deleting the node at given position.If value is given as input then find if that element exist in list and find it's previous node
	cin>>pos;		//pos of node which should be deleted (node are 1 indexed)
	i=1;
	temp=head;		//we have taken temp as head and not head->next because, we could have been asked to delete the first node(so node previous to first node is head only)
	while(i<pos)
	{
		temp=temp->next;
		i++;
	}							//after loop completes we got the pointer previous to node which we want to delete
	if(temp->next->next==NULL)		//if last element is to be deleted
	{
		p=temp->next;
		free(p);
		temp->next=NULL;
	}
	else
	{
		p=temp->next;
		temp->next=p->next;
		free(p);
	}

	head=head->next;
	while(head!=NULL)		//output the created list
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
	return 0;
}

