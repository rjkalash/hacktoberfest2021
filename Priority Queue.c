#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void insert_by_priority(int);
void delete_by_priority(int);
void create();
void check(int);
void display_pqueue();

int pri_que[MAX];
int front, rear;

int main()
{
    int n, ch;
    
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");
    
    create();
    
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1: 
                printf("\nEnter value to be inserted : ");
                scanf("%d",&n);
                insert_by_priority(n);
                break;
            case 2:
                printf("\nEnter value to delete : ");
                scanf("%d",&n);
                delete_by_priority(n);
                break;
            case 3: 
                display_pqueue();
                break;
            case 4: 
                exit(0);
            default: 
                printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
    return 0;
}

/* Function to create an empty priority queue */
void create()
{
    front = rear = -1;
}

/* Function to insert value into priority queue */
void insert_by_priority(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }    
    else
    check(data);
    rear++;
}

/* Function to check priority and place the element in the queue in appropriate position . */
/*Queue contents should always be in descending order*/
void check(int data)
{
    int i,j=front;
  if(data < pri_que[rear])
  {
      pri_que[rear+1]=data;
  }
  else if( data > pri_que[front])
  {
     for(i=rear;i>=front;i--)
     {
         pri_que[i+1]=pri_que[i];
     }
     pri_que[front]=data;
  }
  else
  {
      while(data < pri_que[j])
      {
          j++;
      }
      for(i=rear;i>=j;i--)
      {
          pri_que[i+1]=pri_que[i];
      }
      pri_que[j]=data;
  }

}

/* Function to delete an element from queue */
void delete_by_priority(int data)
{
  int i=front,c=0;
  if(data==pri_que[front])
  {
      front++;
      
  }
  else if(data==pri_que[rear])
  {
      rear--;
  }
  else
  {
  while(i!=rear)
  {
      if(data==pri_que[i])
      {
          c=1;
          break;
      }
      i++;
  }
  if(c==1)
  {
      for(int j=i;j<=rear;j++)
      {
          pri_que[j]=pri_que[j+1];
      }
      rear--;
  }
  else
  {
      printf("\n%d not found in queue to delete",data);
  }
  
}
}

/* Function to display queue elements */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
    
    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }
    
    front = 0;
}
