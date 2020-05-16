from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if nums is None:
            return 0

        cnt = 0
        pre = 0
        mp = {}

        mp[0] = 1
        for x in nums:
            pre += x
            # python3中map移除了has_key方法，直接用in判断
            if pre - k in mp:
                cnt += mp[pre - k]
            
            if pre in mp:
                mp[pre] += 1
            else:
                mp[pre] = 1

        return cnt
