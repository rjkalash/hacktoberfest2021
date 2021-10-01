#include<iostream>
using namespace std;
void create();
void print();
void insert_end();
void insert_beg();
void insert_middle();
void delete_beg();
void delete_end();
void delete_mid();
void search();
void counter();

struct link
{
	int item;
	struct link *next;
};
typedef struct link node;
node *head=NULL;  
int count=0;

int main()
{ int ch;
	   
	   cout<<"1)To create a head node\n";
	   cout<<"2)To insert at the end of list\n";
	   cout<<"3)To print the list\n";
	   cout<<"4)To insert in the beginning of the list\n";
	   cout<<"5)To insert in the middle of the list\n";
	   cout<<"6)To delete an element in the beginning of list\n";
	   cout<<"7)To delete an element in the middle of list\n";
	   cout<<"8)To delete an element in the end of list\n";
	   cout<<"9)To search an element in the list\n";
	   cout<<"10)To count the number of elements in the list\n";
	   do
	   	{
	   	cout<<" Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				print();
				break;
			case 4:
				insert_beg();
				break;
			case 5:
				insert_middle();
				break;
			case 6:
				delete_beg();
				break;
			case 7:
			    delete_mid();
	            break;
			case 8:
			    delete_end();
				break;
			case 9:
			     search();
				 break;	
		    case 10:
		    	counter();
		    	break;
			default:
				cout<<"Wrong choice";
				break;
		}
	}
	while(1);
}

void create()
{
	if(head==NULL)
	{
		head=new node();
		cout<<"Enter item to be inserted\n";
		cin>>head->item;
		head->next = NULL;
		count++;
	}
	else
	{
		cout<<"Head node created";
	}
}

void search()
{ int flag=0;
	int ele; node*p;
	cout<<"Enter element to be searched\n";
	cin>>ele;
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->item==ele)
		{
			cout<<"Element found\n";
			flag =1 ;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"Element not found\n";
	}
}

void print()
{
	node*p;
	p=head;
	cout<<"List is:\n";
	while(p!=NULL)
	{
		cout<<p->item<<endl;
		p=p->next;
	}
}

void insert_end()
{
	if(head==NULL)
	{
	create();
    }
    
    
	node*p;node*q;
	p=head;
	while(p->next != NULL)
	p=p->next;
	q=new node;
	cout<<"Enter item to be inserted in next node\n";
	cin>>q->item;
	q->next=NULL;
	p->next=q;
    count++;
}

void insert_beg()
{
	node*p;
	p=new node;
	cout<<"Enter item to be inserted in beginning of list\n";
	cin>>p->item;
	p->next=head;
	head=p;
	count++;
}

void insert_middle()
{
	int num;node*q;
	cout<<"Enter the item after which you want to insert\n";
	cin>>num;
	node*p=head;
	while(p->item!=num)
	p=p->next;
	q=new node;
	cout<<"Enter the item to be inserted\n";
	cin>>q->item;
	q->next=p->next;
	p->next=q;
	count++;
}

void delete_beg()
{
	node*p;
	p=head;
	head=p->next;
	delete(p);
	count--;
}

void delete_end()
{
	node*p;node*q;
	p=head;
	while((p->next)->next!=NULL)
	p=p->next;
	delete (p->next);
	p->next=NULL;
	count--;
}

void delete_mid()
{
	int ele;
	node*p; node*q;
	cout<<"Enter element to be deleted\n";
     cin>>ele;
    p=head;
	while((p->next)->item!= ele)
	{
		p=p->next;
	}
		q=(p->next);
		p->next=(p->next)->next;
		delete(q);
		count--;	
}

void counter()
{
   cout<<"The number of elements in the list are:"<<count<<endl;	
}
