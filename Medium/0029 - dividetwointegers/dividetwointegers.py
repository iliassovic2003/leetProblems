class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        
        i = 0
        sign = 1

        if (dividend < 0) :
            dividend *= -1
            sign *= -1

        if (divisor < 0) :
            divisor *= -1
            sign *= -1


        if (divisor == 1) :
            if (sign * dividend >= INT_MAX) :
                return INT_MAX
            if (sign * dividend <= INT_MIN) :
                return INT_MIN
            return sign * dividend


        while (dividend >= divisor) :
            temp = divisor
            multiple = 1
            
            while (dividend >= (temp << 1)) :
                temp <<= 1
                multiple <<= 1
    
            
            dividend -= temp
            i += multiple

        if (sign * i >= INT_MAX) :
            return INT_MAX
        if (sign * i <= INT_MIN) :
            return INT_MIN
        return sign * i