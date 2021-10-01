//Code for Perfect palindrome number
//Perfect Palindrome number is a number which is Palindrome as well as Perfect Square
// example: 11 is a perfect palindrome number while 37 is not
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int n)
{
    int sum=0;
    int temp=n;
    while(temp)
    {
        int r=temp%10;
        sum=sum*10+r;
        temp=temp/10;
    }
    return sum==n;
}
bool isPerfectSquare(long double x)
{
    if (x >= 0) {
 
        long long sr = sqrt(x);
         
        return (sr * sr == x);
    }
    return false;
}
int IsPerfectPalindrome(int n)
{
    bool ans=isPalindrome(n) && isPerfectSquare(n);
    return ans==true?1:0;
}
int main()
{
    int n;
    cin>>n;
    cout<<IsPerfectPalindrome(n);
}