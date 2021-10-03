#include<iostream>
using namespace std;
int main()
{int i,j,rows;
int a=0;
cout<<"enter the number of rows to print floyd's triangle:";
cin>>rows;
for(i=1;i<=rows;i++)
{for(j=1;j<=i;j++)
{a++;
cout<<a;}
cout<<endl;
}}
