import sys
from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if nums is None:
            return 0

        min_value, max_value, final_max_value = 1, 1, -sys.maxsize
        for num in nums:
            if num < 0:
                min_value, max_value = max_value, min_value
            
            max_value = max(num, num * max_value)
            min_value = min(num, num * min_value)

            final_max_value = max(max_value, final_max_value)

        return final_max_value
