class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j,n=nums.size();
        vector<int>ans;
        map<int,int>m;
        for(i=0;i<n;i++){
            m[nums[i]]=i;
        }
        //if there are more than one same elements in the array then map[val] gives the last index
        //so for[3,3] 6 it will works when the for loop is in first element it returns ans
        for(i=0;i<n;i++){
            if(m[target-nums[i]]!=0 && i!=m[target-nums[i]])//[8,9] target 16 so if nums[remaining]=same index then we should not consider it
            {
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};
