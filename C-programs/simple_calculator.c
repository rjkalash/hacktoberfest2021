#include<stdio.h>


int main()
{
    int operator=0;
    float a,b,result;
    printf("\n Choose an Operation \n"
            "\t 1) Addition \n "
            "\t 2) Subtraction \n"
            "\t 3) Multiplication \n"
            "\t 4) Division \n"
            "\t 5) Remainder Calculation \n");
    printf("Enter the option number : ");
    scanf("%d",&operator);
    printf("\nEnter the first Operand : ");
    scanf("%f",&a);
    printf("\nEnter the second Operand : ");
    scanf("%f",&b);
    printf("\n");

    switch (operator)
    {
        case 1:
            result = a+b;
            printf("  %f + %f = %f",a,b,result);
            break;
        case 2:
            result = a-b;
            printf("  %f - %f = %f",a,b,result);
            break;
        case  3:
            result = a*b;
            printf("  %f * %f = %f",a,b,result);
            break;
        case 4:
            result = a / b;
            printf("  %f / %f = %f",a,b,result);
            break;
        case 5:
            result = (int)a % (int)b;
            printf("  %f // %f = %d",a,b,(int)result);
            break;
        default:
            printf("Error!! invalid choice.");
}
    return 0;
}