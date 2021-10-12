#include <stdio.h>
int main(void) 
{
	int N,T,i,LastNum,FirstNum;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	   {
	       scanf("%d",&N);
	       LastNum = N%10;
	       while(N!=0)
	       {
	         if(N<10)
	           {
	             FirstNum=N;
	           }
               N=N/10;
	        }    
	       printf("%d\n",FirstNum+LastNum);
	   }
	return 0;
}

