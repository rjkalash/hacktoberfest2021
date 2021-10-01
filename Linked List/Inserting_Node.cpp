#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};
Node *first=NULL;

void create_ll(int A[],int n)
{
    Node *ptr,*last;

    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        ptr=new Node;
        ptr->data=A[i];
        ptr->next=NULL;
        last->next=ptr;
        last=ptr;
    }
}

void display(Node *ptr)
{
    while(ptr)
    {
        cout<<ptr->data<<" -> ";
        ptr=ptr->next;
    }
}

void insert(Node *ptr,int val, int index)
{
    int i=1;
    
    Node *t=new Node;
    t->data=val;
    t->next=NULL;
     
    if(index==1)
    {
        t->next=first;
        first=t;
    }
    
   else{
    while(ptr)
    {
        if(i==index-1)
        {
          t->next=ptr->next;
          ptr->next=t;
          break;
        }
        ptr=ptr->next;
        i++;
    }
   }
}

int main()
{
    int A[]={1,2,3,4,6};
    int data,index;
    cin>>data>>index;
    create_ll(A,5);
    display(first);
    cout<<endl;
    insert(first,data,index);
    display(first);

}
