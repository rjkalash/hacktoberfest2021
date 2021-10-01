#include<bits/stdc++.h>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        next = NULL;
    }
};

Node* takeinput_better() {
    cout<<"Enter the data in your linked list: "<<endl;
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data!= -1) {

       Node* newNode = new Node(data);
       if(head == NULL) {
           head = newNode;
           tail = newNode;
       } 
       else {
           tail -> next = newNode;
           tail = tail -> next;
       }
       cin>>data;
    }
    return head;
}

int length(Node* head) {
    Node* temp = head;
    int length = 0;
    while(temp != NULL) {
      temp = temp -> next;
      length++;
    }
    temp = head;
    int mid = (length -1)/2;
    for(int i=0; i<mid; i++){
        temp = temp -> next;
    }
    int curl = temp -> data;
    return curl;
}

void print(Node* head) {

    Node* temp = head;
    while(temp != NULL) {
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
   Node* head = takeinput_better();
   print(head);
   cout<<"The mid of the given linked list is: "<< length(head) <<endl;
   return 0;
}