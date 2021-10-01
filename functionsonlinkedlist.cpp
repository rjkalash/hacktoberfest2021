#include<iostream>
#include<process.h>
#include<stdlib.h>
using namespace std;
struct Student{
	int data;
	Student* next;
}*start=NULL,*ptr=NULL,*newptr=NULL, *rear=NULL;
class single_llist
{// if you want multiple lists make start a public data member of this class
    public:
        Student* CreateElement(int);
        int count(Student*);
        void Insert_begin(Student *);
        void insert_pos();
        void Insert_end(Student*); 
        void Deletion_front();
        void delete_pos();//check
        void Sort();//check
        void search();//check
        void update();//check
        void reverse();//check
        void Display(Student*);
        single_llist() 
        {
            start = NULL;
        }
};
int single_llist::count(Student* ptr)
{
	int i=0;
	while(ptr)
	{
		ptr=ptr->next;
		i++;
	}
	return i;
}
Student* single_llist::CreateElement(int no)
{
	newptr= new Student; 
	if(newptr==NULL)
	{
		cout<<"Memory could not be alloted";
		Display(start);
		exit(-1);
	}
	else{
	newptr->data=no;
	newptr->next=NULL;}
	return newptr;
}
void single_llist::Insert_begin(Student* ptr)
{
	if(start==NULL){
	start=ptr;
	rear=ptr;
}
	else
	{
		ptr->next=start;
		start=ptr;
	}
}
void single_llist::Deletion_front()
{
if(start==NULL)
{
cout<<"Underflow";
exit(-2);}
else if(start==rear)
{
	Student* p=start;
	start=rear=NULL;
		delete p;
}
else{
	Student* p=start;
	start=start->next;
	delete p;
}	
}
void single_llist::delete_pos()
{
    int pos, i, counter = 0;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    cin>>pos;
    struct Student *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                 s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        delete s;
        cout<<"Element Deleted"<<endl;
    }
}
void single_llist::update()
{
    int value, pos, i;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the node postion to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
    struct Student *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start->data = value; 
    }
    else
    {
        for (i = 0;i < pos - 1;i++)
        {
            if (s == NULL)
            {
                cout<<"There are less than "<<pos<<" elements";
                return;
            }
            s = s->next;
        }
        s->data = value;  
    }
    cout<<"Node Updated"<<endl;
} 
void single_llist::search()
{
    int value, pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
    struct Student *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->data == value)
        {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;  
}
void single_llist::reverse()
{
    struct Student *ptr1, *ptr2, *ptr3;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if (start->next == NULL)
    {
        return;
    }  
    ptr1 = start;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;         
    }
    start = ptr2;
}
void single_llist::Display(Student* link)
{
cout<<"\n";
	while(link!=NULL)
	{
		cout<<link->data<<"\t";
		link=link->next;
	}
}
void single_llist::Insert_end(Student* p)
{
	if(start==NULL)
	start=rear=p;
	else
	rear->next=p;
	rear=p;
}
void single_llist::insert_pos()
{
    int value, pos; 
    cout<<"\nEnter the value to be inserted: ";
    cin>>value;
    struct Student *temp,*ptr, *prev;
    temp = this->CreateElement(value);
    cout<<"\nEnter the postion at which node to be inserted: ";
    cin>>pos;
    int i=1;
    if (pos == 1)
    {
Insert_begin(temp);
    }
    else if (pos > 1){
    	prev=start;
    	ptr=start;
    	while(ptr->next&&pos!=i)
    	{
    		prev=ptr;
    		ptr=ptr->next;
			i++;	
		}
		if(ptr==rear&&pos==i+1)
		{
			Insert_end(temp);
		}
		else if(ptr->next&&pos==i){
		temp->next= ptr;
		prev->next=temp;}
		else
			cout<<"No insertion allowed at position: "<<pos;
	}}
void single_llist::Sort()
{
    struct Student *ptr, *s;
    int value;
    if (start == NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->data > s->data)
            {
                value = ptr->data;
                ptr->data = s->data;
                s->data = value;
            }
        }
        ptr = ptr->next;
    }
}
int main()
{
	single_llist list;
	int no,n;
	char reply;
	cout<<"Create a linked list:"<<endl;
	do
	{
		cout<<"Enter data:";
		cin>>no;
		ptr=list.CreateElement(no);//ptr=newptr
		list.Insert_begin(ptr);
		cout<<"Do you want to create any more elements:"<<endl;
		cin>>reply;
	}while(reply=='y'||reply=='Y');
	list.Display(start);
	cout<<"\nCount:"<<list.count(start);
	cout<<"\nEnter y or Y if you wish to add elements at the end:";
	scanf(" %c",&reply);//wasting a \n
	while(reply=='y'||reply=='Y'){
		cout<<"Enter data:";
		cin>>no;
		ptr=list.CreateElement(no);
		list.Insert_end(ptr);
		cout<<"Do you want to create any more elements:"<<endl;
		cin>>reply;
	}
	list.Display(start);
	cout<<"\nCount:"<<list.count(start);
	cout<<"\nEnter the number of elements to be deleted from front: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		list.Deletion_front();
	}
	list.Display(start);
	cout<<"\nCount:"<<list.count(start);
	cout<<"\nEnter y or Y if you wish to add elements randomly:";
	scanf(" %c",&reply);//wasting a \n
	while(reply=='y'||reply=='Y'){
	list.insert_pos();
	list.Display(start);
	cout<<"\nCount:"<<list.count(start);
	cout<<"\nDo you want to create any more elements:"<<endl;
	cin>>reply;
	}
	cout<<"\nSorting the list and displaying:";
	list.Sort();
	list.Display(start);
}
