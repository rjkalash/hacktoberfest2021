//URL:-https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex=0;
        int max=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] > max)
                {max = nums[i];
                maxIndex = i;}
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] != max && max<2*nums[i])
                return -1;
        }
        
        return maxIndex;
        
    }
};
