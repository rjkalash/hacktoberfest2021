#include<iostream>
using namespace std;

class Queue
{
   public:
   int first;
   int rear;
   int *Arr;
   int length;
};

void Enqueue(Queue *q,int data)
{
    if(q->rear==q->length-1)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        q->rear++;
        q->Arr[q->rear]=data;
    }
}

int Dequeue(Queue *q)
{
    int x=-1;
   if(q->first==q->rear)
   {
       cout<<"Underflow"<<endl;
   }
   else
   {
       q->first++;
       x=q->Arr[q->first];
   }

   if(q->rear==q->first)
   {
       q->rear=-1;
       q->first=-1;
   }
   return x;
}

void Display(Queue q)
{
    for(int i=q.first+1;i<=q.rear;i++)
    {
        cout<<q.Arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
   Queue Q;
   cout<<"Enter the Length: ";
   cin>>Q.length;
   Q.Arr=new int[Q.length];
   Q.first=Q.rear=-1;
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
               Enqueue(&Q,data);
               cout<<"Updated List :";
               Display(Q);
           }
           break;
       case 2:
            {
                cout<<Dequeue(&Q)<<" this element Deleted.";
                cout<<"Updated List:";
                Display(Q);
            }
            break;
        case 3:
            {
                Display(Q);
            }
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
