//link to the problem:https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
//Question:Given an integer number n, return the difference between the product of its digits and the sum of its digits.

class Solution {
public:
    int subtractProductAndSum(int n) {
        int p=1,s=0;
        while(n>0){
            int q=n%10;
            p=p*q;
            s+=q;
            n=n/10;
        }
        return p-s;
    }
};
