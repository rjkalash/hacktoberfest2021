#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>  
#define ele_type int

#define size 5
ele_type q[size];
int front1 = -1, rear1 = -1, front2 = size, rear2 = size;

void enQueue(ele_type val){
    if(rear1==rear2-1){
        printf("Queue is Full!!\n");
    }
    else{
        if(rear1==-1 && front1==-1){
            rear1 = 0;
            front1 = 0;
        }
        else{
            rear1++;
        }
        q[rear1] = val;
        printf("Element is added!!\n");
    }

}

int deQueue(){
    int v;
    if(rear1==-1 && front1==-1){
        printf("Queue is Empty!!\n");
    }
    else{
        v=q[front1];
        printf("Deleted element is : %d \n", v);
        if(front1==rear1){
            front1 = -1;
            rear1 = -1;
        }
        else{
            front1++;
        }
    }
    return v;
}

void inject(ele_type val){
    if(rear1==rear2-1){
        printf("Queue is Full!!\n");
    }
    else{
        if(rear2==size && front2==size){
            rear2 = size-1;
            front2 = size-1;
        }
        else{
            rear2--;
        }
        q[rear2] = val;
        printf("Element is added!!\n");
    }
}

int eject(){
    int v;
    if(rear2==size && front2==size){
        printf("Queue is Empty!!\n");
    }
    else{
        v=q[front2];
        printf("Deleted element is : %d \n", v);
        if(front2==rear2){
            front2 = size;
            rear2 = size;
        }
        else{
            front2--;
        }
    }
    return v;
}

void display1(){
    if(front1==-1 && rear1==-1){
        printf("Queue is Empty!!\n");
    }
    else{
        printf("Queue is : ");
        int i=front1;
        for(; i<=rear1; i++){
            printf("%d  ",q[i]);
        }
        printf("\n");
    }
}

void display2(){
    if(front2==size && rear2==size){
        printf("Queue is Empty!!\n");
    }
    else{
        printf("Queue is : ");
        int i=front2;
        for(; i>=rear2; i--){
            printf("%d  ",q[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("**** Implementation of doubly ended queue using arrays ****\n");
    while (1)
    {
        printf("Menu: 1. enQueue, 2. deQueue, 3. Display1, 4. Inject, 5. Eject, 6. Display2, 7. Exit \n");
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
            display1();
            break;
        case 4:
            printf("Enter value to be inserted\n");
            scanf("%d", &val);
            inject(val);
            break;
        case 5:
            val = eject();
            break;
        case 6:
            display2();
            break;
        default:
            exit(0);
        }
    }

    return 0; 
} 