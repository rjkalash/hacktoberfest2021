#include<stdio.h>

void main()
{
int num,i, n, temp, a[50];
temp=0;
printf("Enter the size of the array \n");
scanf("%d",&n);
printf("Enter the elements of the array \n");
for (i=1; i<=n;i++)
{
scanf("%d", &a[i]);
}

printf("\nEnter the number which you want to search :");
scanf("%d", &num);

for (i=1; i<=n; i++)
{
if(num== a[i])
{
printf("\nThe element is found and the position is: %d",i);
printf("\n");
}
else
{
printf("\nElement is not found \n");
}
}
}
