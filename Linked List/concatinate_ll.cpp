#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

Node * creat_ll(Node *ptr,int A[],int n)
{
    ptr=new Node;
    ptr->data=A[0];
    ptr->next=NULL;
    
    Node *current=ptr;

    for(int i=1;i<n;i++)
    {
        Node *temp=new Node;
        temp->data=A[i];
        temp->next=NULL;

        current->next=temp;
        current=temp;
    }
    return ptr;
}

void display(Node *ptr)
{
    while(ptr)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<endl;
}

void concatenate(Node *Fst,Node *Snd)
{
   while(Fst->next!=NULL)
   {
       Fst=Fst->next;
   }
   Fst->next=Snd;
   Snd=NULL;
}

int main()
{
    int A[]={1,2,3,4,5};
    int B[]={6,7,8,9,10};
    
    Node *first=NULL;
    Node *second=NULL;

    int size;
    size=sizeof(A)/sizeof(A[0]);
    first=creat_ll(first,A,size);

    size=sizeof(B)/sizeof(B[0]); 
    second=creat_ll(second,B,size);
    
    cout<<"LL A : ";
    display(first);
    cout<<"LL B : ";
    display(second);

    cout<<"A + B: ";
    concatenate(first,second);
    display(first);
}
