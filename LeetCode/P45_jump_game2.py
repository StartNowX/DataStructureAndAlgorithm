from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return 0

        max_pos, end, cnt = 0, 0, 0
        for i in range(len(nums) - 1):
            if max_pos >= i:
                max_pos = max(max_pos, i + nums[i])
                if i == end:
                    end = max_pos
                    cnt += 1
        
        return cnt

if __name__ == "__main__":
    sln = Solution()
    nums = [2, 3, 0, 1, 4]

    res = sln.jump(nums)
    print("res = %d" %res)