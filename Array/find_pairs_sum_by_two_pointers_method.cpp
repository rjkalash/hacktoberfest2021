#include<iostream>
using namespace std;

int main()
{
    int size;
    cin>>size;
    
    int ptr[size];
    
    cout<<"Enter the Elements !!"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>ptr[i];
    }
    
    int element;
    cout<<"Enter the Key Which You Wants to Search of Addition !!"<<endl;
    cin>>element;

    int front = 0;
    int end = size - 1;

    while(front<end)
    {
        if(ptr[front]+ptr[end]==element)
        {
            cout<<ptr[front] << " + " << ptr[end] << " = " <<element<<endl;
            end--;
            front++;
        }
        else if(ptr[front]+ptr[end] > element)
        {
            end--;
        }
        else
        {
            front++;
        }
    }
}
