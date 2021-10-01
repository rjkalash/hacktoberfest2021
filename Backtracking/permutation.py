 def permute(self, nums: List[int]) -> List[List[int]]:
        self.result = []
        self.helper(nums, 0)
        return self.result
    
    def helper(self, nums, index):
        if index == len(nums):
            self.result.append(nums[::])
        
        # We choose nums[i]. Swap it with nums[index]. Then we make the recursive call.
        for i in range(index, len(nums)):
            nums[i], nums[index] = nums[index], nums[i]
            self.helper(nums, index + 1)
            nums[i], nums[index] = nums[index], nums[i]
