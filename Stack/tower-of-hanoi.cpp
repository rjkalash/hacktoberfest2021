// C++ Program for Iterative Tower of Hanoi
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
struct Stack
{
unsigned capacity;
int top;
int *array;
};
 
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack =
        (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array =
        (int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}
 
int isFull(struct Stack* stack)
{
return (stack->top == stack->capacity - 1);
}
 
int isEmpty(struct Stack* stack)
{
return (stack->top == -1);
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack -> array[++stack -> top] = item;
}
 

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack -> array[stack -> top--];
}
 
void moveDisk(char fromPeg, char toPeg, int disk)
{
    cout <<"Move the disk " << disk <<" from " << fromPeg << " to "<< toPeg << endl;
}
 

void moveDisksBetweenTwoPoles(struct Stack *src,
            struct Stack *dest, char s, char d)
{
    int pole1TopDisk = pop(src);
    int pole2TopDisk = pop(dest);
 
    // When pole 1 is empty
    if (pole1TopDisk == INT_MIN)
    {
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
 
    // When pole2 pole is empty
    else if (pole2TopDisk == INT_MIN)
    {
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
 
    // When top disk of pole1 > top disk of pole2
    else if (pole1TopDisk > pole2TopDisk)
    {
        push(src, pole1TopDisk);
        push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
 
    // When top disk of pole1 < top disk of pole2
    else
    {
        push(dest, pole2TopDisk);
        push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}
 
void tohIterative(int num_of_disks, struct Stack
            *src, struct Stack *aux,
            struct Stack *dest)
{
    int i, total_num_of_moves;
    char s = 'S', d = 'D', a = 'A';
 
    //If number of disks is even, then interchange
    //destination pole and auxiliary pole
    if (num_of_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a = temp;
    }
    total_num_of_moves = pow(2, num_of_disks) - 1;
 
    //Larger disks will be pushed first
    for (i = num_of_disks; i >= 1; i--)
        push(src, i);
 
    for (i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1)
        moveDisksBetweenTwoPoles(src, dest, s, d);
 
        else if (i % 3 == 2)
        moveDisksBetweenTwoPoles(src, aux, s, a);
 
        else if (i % 3 == 0)
        moveDisksBetweenTwoPoles(aux, dest, a, d);
    }
}

int main()
{
   
    unsigned num_of_disks = 3;
 
    struct Stack *src, *dest, *aux;

    src = createStack(num_of_disks);
    aux = createStack(num_of_disks);
    dest = createStack(num_of_disks);
 
    tohIterative(num_of_disks, src, aux, dest);
    return 0;
}
 
