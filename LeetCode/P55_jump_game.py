from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_index = 0
        for i in range(len(nums)):
            if i > max_index:
                return False

            max_index = max(max_index, i + nums[i])
        
        return True


if __name__ == "__main__":
    sln = Solution()
    nums = [2, 3, 0, 1, 4]

    res = sln.canJump(nums)
    print("res = %d" %res)