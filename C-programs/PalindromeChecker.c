/*
  This program can check whether a number is palindrome or not
  Time complexity : O(Digits of a number)
*/

#include <stdio.h>
int main()
{
    int n, reversed = 0, remainder, original;
    printf("Enter an integer: ");
    scanf("%d", &n);
    original = n;
    while (n > 0) 
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    if (original == reversed)
        printf("%d is palindrome.", original);
    else
        printf("%d isn't palindrome.", original);
    return 0;
}
