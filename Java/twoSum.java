//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
class Solution {
    public static void main(String[] args){
      Scanner scn=new Scanner(System.in);
      int n=scn.nextInt();
      int[] nums=new int[n];
      for(int i=0;i<n;i++)
        nums[i]=scn.nextInt();
      int target=scn.nextInt();
      int[] ans=twoSum(nums,target);
      System.out.println(ans[0]+" "+ans[1]);
    }
  
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(map.containsKey(target-nums[i]))
                return new int[]{i,map.get(target-nums[i])};
            map.put(nums[i],i);
        }
        return new int[]{0};
    }
}
