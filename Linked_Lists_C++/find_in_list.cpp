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
	ll n,i,x;
	cin>>n;
	node p,head,temp;
	head=NULL;
	head=(node)malloc(sizeof(struct Linkedlist));
	temp=head;
	for(i=0;i<n;i++)
	{
		cin>>x;
		p=NULL;
		p=(node)malloc(sizeof(struct Linkedlist));
		p->data=x;
		temp->next=p;
		temp=temp->next;
	}
	temp->next=NULL;

	//finding inputted element in the list
	cin>>x;
	head=head->next;
	i=1;
	while(head!=NULL && head->data!=x)
	{
		i++;
		head=head->next;
	}
	if(i>n)
	{
		cout<<x<<" is not in the list\n";
	}
	else
	{
		cout<<x<<" is at index "<<i<<"\n";
	}
}