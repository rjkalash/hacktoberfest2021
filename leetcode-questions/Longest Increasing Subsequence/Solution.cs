using System.Collections.Generic;
using System.Linq;
using System;
using System.Text;
using System.Collections;

namespace LongestIncreasingSubsequence
{
   /// <summary>
   /// more on: https://github.com/pakosel/leetcode-solutions
   /// </summary>
   public class Solution
   {
      int[] memo;
      public int LengthOfLIS(int[] nums)
      {
         if (nums.Length == 0)
            return 0;
         memo = new int[nums.Length];

         int res = 1;
         for (int i = 0; i < nums.Length; i++)
            res = Math.Max(res, Helper(nums, i));

         return res;
      }
      private int Helper(int[] nums, int start)
      {
         if (memo[start] != 0)
            return memo[start];

         int res = 1;
         for (int i = start + 1; i < nums.Length; i++)
            if (nums[i] > nums[start])
               res = Math.Max(res, 1 + Helper(nums, i));

         memo[start] = res;
         return res;
      }
   }
}