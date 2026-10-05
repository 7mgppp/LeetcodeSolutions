class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        max = float(-inf)
        sum = 0

        for i in range(0, len(nums), 1):
            sum+=nums[i]
            if sum > max:
                max=sum
            if sum < 0:
                sum = 0
        
        if sum < 0:
            max = 0
        
        return max