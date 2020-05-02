import sys
from typing import List

class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        num_len = len(nums)
        if 0 == num_len:
            return 0

        start, sum = 0, 0
        min_len = sys.maxsize
        for i in range(num_len):
            sum += nums[i]

            while sum >= s:
                min_len = min(min_len, i - start + 1)

                sum -= nums[start]
                start += 1
        
        if min_len == sys.maxsize:
            return 0
        else:
            return min_len

if __name__ == "__main__":
    nums = [2,3,1,2,4,3]

    sln = Solution()
    res = sln.minSubArrayLen(7, nums)
    print("res = %d" % res)