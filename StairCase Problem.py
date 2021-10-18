class Solution:
 def climbStair(mine, n: int) -> int:
      one, two = 1,1

      for j in range(n-1):
          temp = one
          one = one+two
          two = temp
          
      return one     