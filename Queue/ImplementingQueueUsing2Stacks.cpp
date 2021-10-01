#include<iostream>
using namespace std;

class stack
{
    public:
    int top;
    int size;
    int *Arr;
};

void push(stack *st,int data)
{
    if(st->top==st->size-1)
    {
        cout<<"Queue Overflow"<<endl;
    }
    else
    {
        st->top++;
        st->Arr[st->top]=data;
    }
}

int pop(stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        cout<<"Queue Underflow"<<endl;
        return x;
    }
    else
    {
        x=st->Arr[st->top];
        st->top--;
    }
    return x;
}

void Display(stack st)
{
    for(int i=0;i<=st.top;i++)
    {
        cout<<st.Arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
   stack st1,st2;
   cout<<"Enter The Size of the Array :"<<endl;
   cin>>st1.size;
   st2.size=st1.size;
   st1.Arr=new int[st1.size];
   st2.Arr=new int[st2.size];
   st1.top=-1;
   st2.top=-1;

//<---Queue--->
int flag=1;
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
               push(&st1,data);
               cout<<"Updated List :";
               Display(st1);
           }
           break;
       case 2:
            {
                if(st2.top==-1)
                {
                    while(st1.top!=-1)
                    {
                        push(&st2,pop(&st1));
                    }
                    cout<<pop(&st2)<<endl;
                }
                else
                {
                    cout<<pop(&st2)<<endl;
                }
            }
            break;
        case 3:
            {
               Display(st1);
            }
       default:
           {
             flag=0;
             cout<<"LogOut"<<endl;
           }
           break;
       }
       if(flag==0)
       {
           break;
       }
   }
}
