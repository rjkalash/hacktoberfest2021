#include <stdio.h>
#include <string.h>
 
int main() 
{
 
  //Initializing variables.
  char str[100];
  int length = 0;
 
  //Accepting inputs.
  printf("Enter a string:\n");
  gets(str);
  
  //Calculating length.
  length = strlen(str);
  
  for(int i=0;i<length;i++)
  {
      if(i==0||i==(length-1)) //Conerting character at first and last index to uppercase.
      {
          str[i]=toupper(str[i]);
      }
      else if(str[i]==' ')//Conerting characters present before and after space to uppercase.
      {
          str[i-1]=toupper(str[i-1]);
          str[i+1]=toupper(str[i+1]);
          
      }
  }
  
  //Printing result.
  printf("String after capitalizing first and last letter of each word:\n%s", str);
 
  return 0;
}
