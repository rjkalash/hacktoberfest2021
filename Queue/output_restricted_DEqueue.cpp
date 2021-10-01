#include<iostream>
using namespace std;

//DE-Queue --> o/p restrict (First->Insertion & Deletion) (Rear --> Instertion)

class Queue
{
public:
	int data;
	Queue *next;
};

Queue *first = NULL;
Queue *rear = NULL;

void enqueue(int data)
{
	Queue *temp = new Queue;
	if (temp == NULL)
	{
		cout << "Overflow" << endl;
	}
	else
	{
		temp->data = data;
		temp->next = NULL;

		if (first == NULL)
		{
			first = rear = temp;
		}
		else
		{
			//Instertion at the Rear Pointer
			rear->next = temp;
			rear = temp;

			//Insertion at the first Pointer
			Queue *temp2 = new Queue;
			temp2->data = data;
			temp2->next = first;
			first = temp2;
		}
	}
}

int dequeue()
{
	int x = -1;
	if (first == NULL)
	{
		cout << "UnderFlow" << endl;
		return x;
	}
	else
	{
		Queue *temp = first;
		first = first->next;
		x = temp->data;
		delete(temp);
	}
	return x;
}

void Display()
{
	Queue *ptr = first;
	while (ptr)
	{
		cout << ptr->data << "->";
		ptr = ptr->next;
	}
	cout << endl;

}

int main()
{
	int flag = 0;
	while (true)
	{
		cout << "1. Insertion \n2. Deletion\n3. Display\n4. Exit!" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int data = 0;
			cin >> data;
			enqueue(data);
			cout << "Updated List :";
			Display();
		}
		break;
		case 2:
		{
			dequeue();
            cout << "Updated List:";
			Display();
		}
		break;
		case 3:
		{
			Display();
		}
		break;
		default:
		{
			flag = 1;
			cout << "LogOut" << endl;
		}
		break;
		}
		if (flag != 0)
		{
			break;
		}
	}
}
