#include <stdio.h>
 

int main()
{
    int arr[100], reverse[100];
    int size, i, arrIndex, revIndex;

   
    printf("Enter size of the array: ");
    scanf("%d", &size);

    
    printf("Enter elements in array: \n");
    for(i=0; i<size; i++)
    {
    	printf("a[%d] = ",i);
        scanf("%d", &arr[i]);
    }

    revIndex = 0;
    arrIndex = size - 1;
    while(arrIndex >= 0)
    {
       
        reverse[revIndex] = arr[arrIndex];
        
        revIndex++;
        arrIndex--;
    }

    
    printf("\nReversed array : ");
    for(i=0; i<size; i++)
    {
        printf("%d ", reverse[i]);
    }

   
}
