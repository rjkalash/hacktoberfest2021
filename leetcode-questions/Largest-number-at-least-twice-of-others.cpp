class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto max=max_element(nums.begin(),nums.end())-nums.begin();
        for(int i=0;i<nums.size();i++){
            if(max==i)
                continue;
            if(nums[max]<2*nums[i])
                return -1;
        }
        return max;
    }
};