#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>  
#define ele_type int

#define size 5
ele_type q[size];
int front = -1,rear = -1;

void enQueue(ele_type val){
    if((rear==size-1 && front==0) || front==rear+1){
        printf("Queue Is Full\n");
    }
    else{
        if(rear==size-1){
            rear = 0;
        }
        else{
            rear++;
        }
        q[rear] = val;
        if(front==-1){
            front = 0;
        }
    } 
}

int deQueue(){
    int v;
    if(front==-1 && rear==-1){
        printf("Queue Is Empty!!\n");
    }
    else{
        v=q[front];
        printf("Deleted element is %d \n", q[front]);
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else if(front==size-1){
            front = 0;
        }
        else{
            front++;
        }
    }
    return v;
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is Empty!!\n");
    }
    else{
        int i = front;
        printf("Queue is : ");
        if(front<=rear){
            while (i<=rear)
            {
                printf("%d  ", q[i]);
                i++;
            }
        }
        else{
            while (i<=size-1)
            {   
                printf("%d  ", q[i]);
                i++;
            }
            i = 0;
            while (i<=rear)
            {
                printf("%d  ", q[i]);
                i++;
            }
        }
        printf("\n");
    }
}

int main() {
    printf("**** Implementation of circular queue using arrays ****\n");
    while (1)
    {
        printf("Menu: 1. enQueue, 2. deQueue, 3. Display \n");
        int n,val;
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter value to be inserted\n");
            scanf("%d", &val);
            enQueue(val);
            break;
        case 2:
            val = deQueue();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0; 
} 