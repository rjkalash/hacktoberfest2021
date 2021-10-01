#include<iostream>
using namespace std;

class queue
{
    public:
    int first;
    int rear;
    int *Arr;
    int size;
};

void enqueue(queue *ptr,int data)
{
    if(ptr->rear+1 % ptr->size == ptr->first)
    {
        cout<<"OverFlow"<<endl;
    }
    else
    {
      ptr->rear = ptr->rear +1 % ptr->size;
      ptr->Arr[ptr->rear]=data;
    }
}

int dequeue(queue  *ptr)
{
    int x=-1;
    if(ptr->first == ptr->rear)
    {
        cout<<"UnderFlow"<<endl;
    }
    else
    {
        ptr->first = ptr->first + 1 % ptr->size;
        x=ptr->Arr[ptr->first];
    }
    return x;
}

void Display(queue ptr)
{
    int i=ptr.first+1;
    do
    {
      cout<<ptr.Arr[i]<<" ";
      i=(i+1)%ptr.size;
    }while(i!=(ptr.rear+1)%ptr.size);
    cout<<endl;
}

int main()
{
    queue Q;
    cout<<"Enter the Size :";
    cin>>Q.size;
    Q.first=Q.rear=0;

    Q.Arr=new int[Q.size];
     
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
               enqueue(&Q,data);
               cout<<"Updated List :";
               Display(Q);
           }
           break;
       case 2:
            {
                cout<<dequeue(&Q)<<" this element Deleted.";
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
