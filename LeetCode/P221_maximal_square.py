from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0

        rows, cols = len(matrix), len(matrix[0])
        dp = [[0] * cols for _ in range(rows)]
        max_side = 0

        for r in range(rows):
            for c in range(cols):
                if matrix[r][c] == '1':
                    if r == 0 or c == 0:
                        dp[r][c] = 1
                    else:
                        dp[r][c] = min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1]) + 1
                    
                    max_side = max(max_side, dp[r][c])
        
        return max_side * max_side