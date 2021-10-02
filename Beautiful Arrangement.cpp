/*
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.
Link - https://leetcode.com/problems/beautiful-arrangement/
*/

class Solution {
    void calculate(int n, int pos, vector<bool> &v, int *count){
        // valid permutation so count+1
        if(pos>n){
            (*count)++;
        }
      
        for(int i=1; i<=n; ++i){
            // if number is not visited for current permutation and one of the condition is satisfied
            if(!v[i-1] && (pos%i==0 || i%pos==0)){
                v[i-1]=true; // first mark it as visited
                calculate(n, pos+1, v, count); // make a recursive call for going further
                v[i-1]=false; // mark it as not visited as current permutation is over
            }
        }
    }
public:
    int countArrangement(int n) {
        vector<bool> v(n, false); // to keep check of used numbers for current permutation
        int count=0;
        calculate(n, 1, v, &count);
        return count;
    }
};
