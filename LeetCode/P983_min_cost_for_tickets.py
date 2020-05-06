from typing import List

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        last_day = days[len(days) - 1]

        dp = [0] * (last_day + 1)
        idx = 0
        for i in range(1, last_day + 1):
            if i == days[idx]:
                cost = sys.maxsize

                day1_ago = i - 1
                day7_ago = i - 7 if i - 7 > 0 else 0
                day30_ago = i - 30 if i - 30 > 0 else 0

                cost = min(cost, dp[day1_ago] + costs[0])
                cost = min(cost, dp[day7_ago] + costs[1])
                cost = min(cost, dp[day30_ago] + costs[2])

                dp[i] = cost
                idx += 1
            else:
                dp[i] = dp[i - 1]
        
        return dp[last_day]

