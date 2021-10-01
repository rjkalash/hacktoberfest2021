/*  Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.
Example1:  
Input: arr[]   = {2, 0, 2}
Output: 2
Explanation: |   | 
			       |   |
			       ------
			       2 0 2
Here consider '|' as block and we can see that we can store 2units of water in between the bolcks of height 2.....
so the answer is 2.
Example2:
Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7
Explanation:         |
             |       |
             |   |   |
             |   |   |
             ----------
             3 0 2 0 4
From the above diagram it clear that we can stor::  3 unit at 1(index), 1 unit at 2(index), 3 unit at 3(index), therefore 3+1+1=7.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000
#define SIZE 7

//Implementing Integer stack
struct stack
{
	int a[MAX];
	int top;
};
typedef struct stack stack;
void push(stack* p,int k)
{
	*(p->a+p->top+1)=k;
	p->top=p->top+1;
}
int pop(stack* p)
{
	int temp=*(p->a+p->top);
	p->top=p->top-1;
	return temp;
}
stack* create()
{
	stack* s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	return s;
}
int isempty(stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}


void left(int *a, int size,int *res) //calculating left maximum array
{
	int i,max=0;
	for(i=0;i<size;i++)
	{
		if(*(a+i)>max)
		{
			max=*(a+i);
			*(res+i)=max;
		}
		else
		{
			*(res+i)=max;
		}
	}
}
void right(int *a, int size,int *res)//calculating the left maximum array
{
	int i,max=0;
	for(i=size-1;i>=0;i--)
	{
		if(*(a+i)>max)
		{
			max=*(a+i);
			*(res+i)=max;
		}
		else
		{
			*(res+i)=max;
		}
	}
}

int min(int a,int b) //calculating minimum of two numbers
{
	if(a<b)
		return a;
	else
		return b;
}

int rain(int* a, int size)// for caculating the solution for the above problem
{
	int* l=(int *)malloc(sizeof(int)*size);
	int* r=(int *)malloc(sizeof(int)*size);
	left(a,size,l);
	right(a,size,r);
	int water=0;
	int i;
	for(i=0;i<size;i++)
	{
		water=water+min(*(l+i),*(r+i))-*(a+i);
	}
	return water;
}
void main()
{
	int a[]={6,2,5,4,5,1,6};
	int harvest=rain(a,SIZE);
	printf("%d",harvest);
}
