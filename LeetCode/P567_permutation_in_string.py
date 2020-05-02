from collections import defaultdict

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mp = defaultdict(int)

        dict = {}
        for e in s1:
            mp[e] += 1
        
        left, right = 0, 0
        while right < len(s2):
            c = s2[right]
            right += 1

            mp[c] -= 1

            while left < right and mp[c] < 0:
                mp[s2[left]] += 1
                left += 1
            
            if right - left == len(s1):
                return True
        
        return False


if __name__ == "__main__":
    sln = Solution()

    s1 = "adc"
    s2 = "dcda"
    res = sln.checkInclusion(s1, s2)
    print("res = ", res)
