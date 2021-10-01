#include<iostream>
using namespace std;

class Queue{

public:
    Queue *next;
    int data;
};
Queue *first=NULL;
Queue *rear=NULL;

void enqueue(int d)
{
   Queue *temp=new Queue;
   if(temp==NULL)
   {
       cout<<"OverFlow"<<endl;
   }
   else
   {
       temp->data=d;

       if(first==NULL){
           first=rear=temp;
           rear->next=NULL;
       }
       else
       {
           rear->next=temp;
           rear=temp;
           rear->next=NULL;
       }
   }
}

int dequeue()
{
   int x=-1;
   if(first==NULL)
   {
       cout<<"UnderFlow"<<endl;
   }
   else
   {
   Queue *dummy=first;
   first=first->next;
   x=dummy->data;
   delete(dummy);
   }
   return x;
}

void Display()
{
  Queue *temp=first;
  while(temp!=NULL)
  {
      cout<<temp->data<<"->";
      temp = temp->next;
  }
  cout<<endl;
}

int main()
{
  int flag=0;
  while(true)
   {
       cout<<"1. Insertion \n2. Deletion\n3. Display\n4. Exit!"<<endl;
       int choice=0;
       cin>>choice;
       switch (choice)
       {
       case 1:
           {
               int data=0;
               cin>>data;
               enqueue(data);
               cout<<"Updated List :";
               Display();
           }
           break;
       case 2:
            {
                cout<<dequeue()<<" this element Deleted.\n";
                cout<<"Updated List:";
                Display();
            }
            break;
        case 3:
            {
                Display();
            }
            break;
       default:
           {
             flag=1;
             cout<<"LogOut"<<endl;
           }
           break;
       }
       if(flag!=0)
       {
           break;
       }
   }
}
