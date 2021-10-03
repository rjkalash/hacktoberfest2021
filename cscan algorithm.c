#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void scanright(int a[20],int n,int loc)
{
 int count=0,i,diff,flag;
 float avg;
 for(i=loc;i<n;i++)
 {
  diff=abs(a[i+1]-a[i]);
  count+=diff;
 }
 flag=i;

 for(i=loc-1;i>=0;i--)
 {
  diff=abs(a[flag]-a[i]);
  count+=diff;
  flag=i;
 }

 printf("\nSeek sequence is:");
 for(i=loc+1;i<=n;i++)
  printf("%d\t",a[i]);
 for(i=loc-1;i>=0;i--)
  printf("%d\t",a[i]);
 avg=(float)count/n;
 printf("\nTotal Seek time:%d",count);
 printf("\nAverage Seek time:%.2f",avg);
}

void scanleft(int a[20],int n,int loc)
{
 int count=0,i,diff,flag;
 float avg;
 for(i=loc;i>0;i--)
 {
  diff=abs(a[i]-a[i-1]);
  count+=diff;
 }
 flag=i;
 for(i=loc+1;i<=n;i++)
 {
  diff=abs(a[i]-a[flag]);
  count+=diff;
  flag=i;
 }
 printf("\nSeek sequence is:");
 for(i=loc-1;i>=0;i--)
  printf("%d\t",a[i]);
 for(i=loc+1;i<=n;i++)
  printf("%d\t",a[i]);
 avg=(float)count/n;
 printf("\nTotal Seek time:%d",count);
 printf("\nAverage Seek time:%.2f",avg);
}
void main()
{
 int a[20],i,j,temp,n,head,loc;
 char dir[10];
 printf("\nEnter initial head position:");
 scanf("%d",&head);
 printf("\nEnter request count & direction");
 scanf("%d%s",&n,dir);
 for(i=1;i<=n;i++)
 {
  printf("\nEnter request value %d:",i);
  scanf("%d",&a[i]);
 }
 a[0]=head;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 for(i=0;i<n;i++)
 {
  if(a[i]==head)
  {
   loc=i;
   break;
  }
 }
 if(strcmp(dir,"left")==0)
 {
  scanleft(a,n,loc);
 }
 else
 {
  scanright(a,n,loc);
 }
}

