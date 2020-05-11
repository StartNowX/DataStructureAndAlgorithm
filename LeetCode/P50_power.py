class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if x == 0:
            return 0
        
        return self.PowCore(x, n) if n > 0 else 1.0 / self.PowCore(x, -n)

    def PowCore(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n == 1:
            return x
        
        res = self.PowCore(x, n // 2)
        return res * res if n & 1 == 0 else res * res * x