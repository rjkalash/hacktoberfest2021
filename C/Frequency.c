#include<stdio.h>

int main(){
	char a[100],ch;
	int i,count=0;
	
	printf("enter the string:");
	gets(a);
	
	printf("\none character to find frequency:");
	scanf("%c",&ch);
	
	for(i=0;a[i]!=0;i++){
		if(ch==a[i])
		   count++;
	}
	
	printf("\nfrequency of %c = %d",ch,count);
	
	return 0;
	
}
