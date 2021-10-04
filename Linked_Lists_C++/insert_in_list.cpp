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
        head=NULL;              //assigning nothing to head node
        head=(node)malloc(sizeof(struct Linkedlist));
        temp=head;
        for(i=0;i<n;i++)
        {
                cin>>x;
                node p;
                p=NULL;         //assigning nothing to node p;
                p=(node)malloc(sizeof(struct Linkedlist));
                p->data=x;
                temp->next=p;                   //assigning next pointer of temp as p
                temp=temp->next;
        }
        temp->next=NULL;

        //inserting the inputted element after given index
        cin>>pos>>x;            //1 based indexing...if pos is 0 then insert node after 0th element i.e before first element
        temp=head;
        i=0;
        while(i<pos)            //finding node at the pos position
        {
                temp=temp->next;
                i++;
        }
        p=(node)malloc(sizeof(struct Linkedlist));
        p->data=x;
        p->next=temp->next;
        temp->next=p;

        head=head->next;                //coming to the first element
        while(head!=NULL)               //output the created list
        {
                cout<<head->data<<" ";
                head=head->next;
        }
        cout<<"\n";
        return 0;
}
