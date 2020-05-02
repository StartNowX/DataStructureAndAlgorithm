class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s is None:
            return 0
        
        is_exist = set()
        str_len = len(s)
        rk, ans = -1, 0

        for i in range(str_len):
            # while中会一直加只到存在一样的，那么这时候就把最开始的重复的删除掉
            if i != 0:
                is_exist.remove(s[i - 1])
            
            while rk + 1 < str_len and s[rk + 1] not in is_exist:
                is_exist.add(s[rk + 1])
                rk += 1
        
            ans = max(ans, rk - i + 1)
        return ans


if __name__ == "__main__":
    sln = Solution()
    input_str = "abcabcbb"
    str_len = sln.lengthOfLongestSubstring(input_str)
    print("str_len = ", str_len)