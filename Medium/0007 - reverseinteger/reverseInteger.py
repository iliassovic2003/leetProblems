class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        sign = -1 if x < 0 else 1
        reversed_str = str(abs(x))[::-1]
        reversed_num = int(reversed_str) * sign

        if reversed_num > INT_MAX or reversed_num < INT_MIN:
            return 0
        return reversed_num