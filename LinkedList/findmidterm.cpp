#include <iostream>
#include <sstream>

using namespace std;

struct Node
{
    int x;
    Node *next;

    Node()
    {
        this->next = NULL;
    }
} * head, *tail;

void push(int x)
{
    Node *ptr = new Node();
    ptr->x = x;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        tail->next = ptr;
        tail = ptr;
    }
}

void insert(string str)
{
    stringstream ss;
    ss << str;
    while (ss.good())
    {
        int num;
        ss >> num;
        push(num);
    }
}

int find()
{
    Node *node1 = head, *node2 = head;
    for (; node2->next != NULL; node1 = node1->next, node2 = node2->next->next)
    {
        //cout<<node1->x<<' '<<node2->x<<endl ;
        if (!node2->next->next)
            break;
    }
    return node1->x;
}

void display()
{
    try
    {
        Node *node = head;
        if (node == NULL)
            throw "Linked List is Empty.";
        while (node != NULL)
        {
            cout << node->x << "->";
            node = node->next;
        }
        cout << endl;
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }
}
int main()
{
    string str;
    cout << "Enter Node Elements : ";
    getline(cin, str);
    insert(str);
    display();
    cout << "The middle of the linked list :" << find() << endl;
}