/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
using namespace std;
struct Node
{
int data;
Node* next = NULL;
};
class LinkedList
{
Node *head = NULL;
public:
void insertAtBeginning(int val)
{
Node *newNode = new Node();
newNode->data = val;
newNode->next = head;
head = newNode;
}
void insertAtEnd(int val)
{
Node *newNode = new Node();
newNode->data = val;
if (head == NULL)
head = newNode;
else
{
Node *temp;
for (temp = head; temp->next != NULL;
temp = temp->next);
temp->next = newNode;
}
}
void insertAfterItem(int ref, int val)
{
Node *newNode = new Node();
newNode->data = val;
Node *temp;
for (temp = head; temp != NULL && temp->data != ref;
temp = temp->next);
if (temp == NULL)
cout << "Reference node is not present in list!\n";
else
{
newNode->next = temp->next;
temp->next = newNode;
}
}
void insertBeforeItem(int ref, int val)
{
Node *newNode = new Node();
newNode->data = val;
Node *temp, *prev = NULL;
for (temp = head; temp != NULL && temp->data != ref;
temp = temp->next)
prev = temp;
if (temp == NULL)
cout << "Reference node is not present in list!\n";
else if (prev == NULL)
{
newNode->next = temp;
head = newNode;
}
else
{
newNode->next = temp;
prev->next = newNode;
}
}
void deleteStart()
{
Node *temp = head;
if (temp == NULL)
cout <<"List is empty!\n";
else
{
head = head->next;
delete temp;
}
}
void deleteEnd()
{
Node *temp, *prev = NULL;
for(temp = head; temp != NULL && temp->next != NULL;
temp = temp->next)
prev = temp;
if (temp == NULL)
cout << "List is empty!\n";
else if (prev == NULL)
{
delete temp;
head = NULL;
}
else
{
prev->next = NULL;
delete temp;
}
}
void deleteNode(int val)
{
Node *temp, *prev = NULL;
for (temp = head; temp != NULL && temp->data != val;
temp = temp->next)
prev = temp;
if (temp == NULL)
cout << "Node is not present in list!\n";
else if (prev == NULL)
{
head = head->next;;
delete temp;
temp = NULL;
}
else
{
prev->next = temp->next;
delete temp;
temp = NULL;
}
}
void searchNode(int val)
{
Node *temp;
int count = 1;
for (temp = head; temp!= NULL && temp->data != val;
temp = temp->next)
count ++;
if (temp == NULL)
cout << "Node is not present in list!\n";
else
cout << "Node is at position " << count << endl;
}
void show()
{
if (head == NULL)
cout << "List is empty!\n";
else
{
Node *node = head;
for (node; node != NULL; node = node->next)
cout << node->data << " ";
cout << endl;
}
}
};
main()
{
LinkedList list1;
cout << "--- MENU ---\n1. Insertion at the beginning\n"
"2. Insertion at the end\n"
"3. Insertion after node\n"
"4. Insertion before node\n"
"5. Deletion from the beginning\n"
"6. Deletion from the end\n"
"7. Deletion of a specific node\n"
"8. Search for a node value\n"
"9. Display all the nodes\n";
short select;
while (1)
{
cout << "\nSelect operation: ";
cin >> select;
switch (select)
{
case 1:// Inserting at begnning
{
int value;
cout << "Enter node value to add in beginning of list : ";
cin >> value;
list1.insertAtBeginning(value);
break;
}
case 2:// Insertion at the end.
{
int value;
cout << "Enter node value to add in end of list: ";
cin >> value;
list1.insertAtEnd(value);
break;
}
case 3:// Insertion after node
{
int value, refVal;
cout << "Enter reference node value: ";
cin >> refVal;
cout << "Enter value to add after ref node: ";
cin >> value;
list1.insertAfterItem(refVal, value);
break;
}
case 4:// Insertion before node
{
int value, refVal;
cout << "Enter reference node value: ";
cin >> refVal;
cout << "Enter value to add before ref. node: ";
cin >> value;
list1.insertBeforeItem(refVal, value);
break;
}
case 5:// Deletion from the beginning.
{
list1.deleteStart();
break;
}
case 6:// Deletion from the end.
{
list1.deleteEnd();
break;
}
case 7:// Deletion of a specific node value
{
int value;
cout << "Enter node value to delete from a list: ";
cin >> value;
list1.deleteNode(value);
break;
}
case 8:// Search for a node and display its position from head
{
int value;
cout << "Enter node value to search position in a list: ";
cin >> value;
list1.searchNode(value);
break;
}
case 9:// Display all the node values.
{
list1.show();
break;
}
default:// EXIT
{
exit(0);
break;
}
}
}
return 0;
}