class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if nums is None:
            return 0

        dp = [-sys.maxsize + 1] * len(nums)

        dp[0] = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(nums[i], dp[i - 1] + nums[i])

        return max(dp)
    
if __name__ == "__main__":
    sln = Solution()