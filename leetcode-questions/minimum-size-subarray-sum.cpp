class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int n=nums.size();
        int l=0;
        
        int sum=0;
        int result=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            while(sum>=target)
            {
                result=min(result,i+1-l);
                sum=sum-nums[l];
                l++;
            }
            
         
            
                
        }
        return (result!=INT_MAX?result:0);
    }
    
     
};
