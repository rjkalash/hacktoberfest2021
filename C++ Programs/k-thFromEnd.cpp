#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node * next;

    Node(int n){
        this->data=n;
        next=NULL;
    }

};

Node* head = NULL;


void print(Node *head){
  
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtEnd(int data){
    if(head==NULL){
        Node* temp = new Node(data);
        temp->next=NULL;
        head=temp;
    }
    else{
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp ->next;
        }
        Node* temp2 = new Node(data);
        temp->next = temp2;
    }
}

int length(Node* node){
    if(node->next == NULL){
        return 1;
    }
    else if ( node == NULL){
        return 0;
    }
    return length(node->next) + 1;

}

void removeFromEnd(Node* node, int n){
    Node* one = node;
    Node* two = node;
    for (int i = 0; i < n; i++)
    {
        two = two->next;
    }
    if(two == NULL){//length of ll =k
        head = one->next; 
    }
    while (two->next != NULL)   
    {
        two = two->next;
        one = one->next;
    }
    Node* temp = one->next;
    one->next = temp->next;
    free(temp);
}

int main()
{
    int ch;
    cout<<"\n********Enter -1 to terminate input loop********\n";
    while(ch != -1){
        cout<<"Enter the node data:";
        cin>>ch;
        if(ch == -1){
            continue;
        }
        insertAtEnd(ch);
    }
    print(head);
    cout<<"\nLength is : "<<length(head)<<"\n";

    removeFromEnd(head, 3);
    print(head);

    return 0;
}