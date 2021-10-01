#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};


Node *first=NULL;
Node *rear=NULL;

void enqueue(int data)
{
    Node *temp=new Node;
    if(temp==NULL)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        temp->data=data;
        temp->next=NULL;

        if(first==NULL)
        {
          first=rear=temp;   
        }
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }
}

int dequeueFromFirst()
{
   int x=-1;
   if(first==NULL)
   {
       cout<<"Underflow"<<endl;
   }
   else
   {
       Node *temp=first;
       first=first->next;
       x=temp->data;

       delete(temp);
   }
   return x;
}

int dequeueFromRear()
{
  int x=-1;
  if(first==NULL)
  {
      cout<<"UnderFlow"<<endl;
  }
  else
  {
      Node *ptr=first;
      while(ptr->next!=rear)
      {
          ptr=ptr->next;
      }

      rear=ptr;
      ptr=ptr->next;
      rear->next=NULL;

      x=ptr->data;
      delete(ptr);
  }
  return x;
}

void Display()
{
    Node *temp=first;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
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
                cout<<dequeueFromFirst()<<" this element is Deleted from the First Pointer.\n && \n"<<dequeueFromRear()<<" this element is deleted from the rear pointer.\n";
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
