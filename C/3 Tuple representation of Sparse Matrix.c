#include <stdio.h>
void main()
{
    int a[100][100], row, col, i, j;
    printf("Enter the no. of rows and columns of the matrix:");
    scanf("%d %d", &row, &col);
    
    printf("\nEnter a Sparse Matrix:");
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    printf("\nThe 3 tuple representation of the Sparse Matrix:");
    
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
        {
            if(a[i][j]!=0)
            {
                printf("\n %d %d %d", i, j, a[i][j]);
            }
        }
    printf("\n");
}



