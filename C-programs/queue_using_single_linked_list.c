#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define ele_type int

typedef struct QUEUE q;
struct QUEUE {
    ele_type data;
    q* next;
}* front=NULL, *rear=NULL;

void enQueue(ele_type val){
    q* new_node=(q *)malloc(sizeof(q));
    new_node->data=val;
    new_node->next = NULL;

    if(rear==NULL){
        rear=new_node;
        front=new_node;
    }
    else{
        rear->next=new_node;
        rear=new_node;
    }
}

int deQueue(){
    int v;
    if(rear==NULL && front==NULL){
        printf("Queue is empty\n");
    }
    else{
        q *temp = front;
        v = temp->data;
        printf("Deleted element is : %d \n", temp->data);
        if(front==rear){
            front = NULL;
            rear = NULL;
        }
        else{
            front = front->next;
        }
    }
    return v;
}

void display(){
    q *temp = front;
    if(rear==NULL){
        printf("Queue is empyty!! \n");
    }
    else{
        printf("Queue is : ");
        while (temp!=rear->next)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    printf("**** Implementation of queue using single linked list ****\n");
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