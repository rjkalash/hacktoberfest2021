# Python program to find maximum contiguous subarray
# using kaden's algorithm

def maxSubArraySum(a,size):
	
	max_so_far =a[0]
	curr_max = a[0]
	
	for i in range(1,size):
		curr_max = max(a[i], curr_max + a[i])
		max_so_far = max(max_so_far,curr_max)
		
	return max_so_far

# Driver function to check the above function
print("Enter number of numbers: ", end='')
n=int(input())
print("Enter numbers: ", end='')
nums = [int(i) for i in input().split()]

print("Maximum contiguous sum is" , maxSubArraySum(nums,n))

