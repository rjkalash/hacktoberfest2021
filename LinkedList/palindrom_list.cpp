#include <stdio.h>  
#include <stdbool.h>  
   
//Represent a node of the singly linked list  
struct node{  
    int data;  
    struct node *next;  
};      
   
//Represent the head and tail of the singly linked list  
struct node *head, *tail = NULL;  
int size = 0;  
   
//addNode() will add a new node to the list  
void addNode(int data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, both head and tail will point to new node  
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode will become new tail of the list  
        tail = newNode;  
    }  
    //Size will count the number of nodes present in the list  
    size++;  
}  
   
//reverseList() will reverse the singly linked list and return the head of the list  
struct node* reverseList(struct node *temp){  
    struct node *current = temp;  
    struct node *prevNode = NULL, *nextNode = NULL;  
      
   //Swap the previous and next nodes of each node to reverse the direction of the list  
    while(current != NULL){  
        nextNode = current->next;  
        current->next = prevNode;  
        prevNode = current;  
        current = nextNode;  
    }  
    return prevNode;  
}  
   
//isPalindrome() will determine whether given list is palindrome or not.  
void isPalindrome(){  
    struct node *current = head;  
    bool flag = true;  
      
    //Store the mid position of the list  
    int mid = (size%2 == 0)? (size/2) : ((size+1)/2);  
      
    //Finds the middle node in given singly linked list  
    for(int i=1; i<mid; i++){  
        current = current->next;  
    }  
      
    //Reverse the list after middle node to end  
    struct node *revHead = reverseList(current->next);  
   
    //Compare nodes of first half and second half of list  
    while(head != NULL && revHead != NULL){  
        if(head->data != revHead->data){  
            flag = false;  
            break;  
        }  
        head = head->next;  
        revHead = revHead->next;  
    }  
   
    if(flag)  
        printf("Given singly linked list is a palindrome\n");  
    else  
        printf("Given singly linked list is not a palindrome\n");  
}  
      
//display() will display all the nodes present in the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
      
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of singly linked list: \n");  
    while(current != NULL) {  
        //Prints each node by incrementing pointer  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
      
int main()  
{  
    //Add nodes to the list  
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(2);  
    addNode(1);  
      
    display();  
      
    //Checks whether given list is palindrome or not  
    isPalindrome();  
      
    return 0;  
}  
