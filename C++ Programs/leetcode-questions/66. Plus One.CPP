/*Created by Lakshay Goel
  Github Profile link: https://github.com/MrLakshay
  
  
   Question link: https://leetcode.com/problems/plus-one
   Problem statement : You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
  The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
  Increment the large integer by one and return the resulting array of digits.
  Runtime: 4 ms O(n)
  Memory Usage: 8.9 MB
  Sample test case :
  Your input: [9]
  Output: [1,0]
  Expected: [1,0]
  
  Approach :
  Receive input in the form of vector.
  We calaculate the size of vector.
  If digit is less that 9 we simply add one to present element else present element is made zero and next element is increment by one
  this cycle keep on going till we find digit less than 9 if not found we increase the vector size by one
  and place one in that additional space created. 
  Return the resulting vector.
  
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) { //receiving input in the form of vector 
        int n=digits.size();  //we calaculate the size of vector using 'size()' function 
        for(int i=n-1;i>=0;i--) 
        {
            if(digits[i]<9)   //if digit is less that 9 we simply add one to present element else present element is made zero and next element is increment by one
            {digits[i]++ ; return digits;} //this cycle keep on going till we find digit less than 9 if not found we increase the vector size by one
            else                  //and place one in that additional space created
                digits[i]=0;
        }
        vector<int>num(n+1,0);
        num[0]=1;
        return num;
    }
};
