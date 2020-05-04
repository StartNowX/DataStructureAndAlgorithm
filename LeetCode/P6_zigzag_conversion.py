class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        
        rows = [''] * min(numRows, len(s))
        cur_row = 0
        direction = False
        for c in s:
            rows[cur_row] += c
            if cur_row == 0 or cur_row == numRows - 1:
                direction = (~direction)
            
            cur_row += (1 if direction else -1)

        ret = ''
        for s in rows:
            ret += s
        
        return ret

if __name__ == "__main__":
    sln = Solution()
    s = "PAYPALISHIRING"
    res = sln.convert(s, 3)
    print("res = ", res)