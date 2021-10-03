//sorting the stack using c.
#include <stdio.h>
#define ll long long
void sortStack(int input[],int size) 
{ 
  int tmpStack[size];
  int top=-1;
  while (size>=0) 
  { 
      int tmp = input[size]; 
      size--; 
      // while temporary stack is not empty and top 
      // of stack is greater than temp 
      while (top>=0 && tmpStack[top] < tmp) 
      { 
          // pop from temporary stack and push 
          // it to the input stack 
          input[++size]=tmpStack[top]; 
          top--;
      } 
      // push temp in tempory of stack 
      tmpStack[++top]=(tmp); 
  } 
  while (top>=0) 
  { 
      printf("%d ",tmpStack[top]); 
      top--;
  } 
} 
int main()
{  
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,x;
    scanf("%d",&n);
    int input[n];int top=-1;
    for(int i=0;i<n;i++){
      scanf("%d",&x);
      input[++top]=x;

    }

    // This is the temporary stack 
    sortStack(input,top); 
    printf("\n");

    }
  return 0;
 }
