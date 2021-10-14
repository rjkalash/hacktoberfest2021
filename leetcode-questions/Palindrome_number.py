class Solution:
def isPalindrome(self, x: int) -> bool:
x = str(x)
if x[::-1] == x[::]:
return True
else:
return False
