#include <limits.h>
#include <iostream>

class Solution {
    public:
        int divide(int dividend, int divisor)
        {
            long i = 0;
            long x = dividend;
            long y = divisor;

            int sign = 1;

            if (x < 0)
            {
                x *= -1;
                sign *= -1;
            }
            if (y < 0)
            {
                y *= -1;
                sign *= -1;
            }

            if (y == 1)
            {
                if (sign * x >= INT_MAX)
                    return INT_MAX;
                if (sign * x <= INT_MIN)
                    return INT_MIN;
                return sign * x;
            }

            while (x >= y)
            {
                long temp = y;
                long multiple = 1;
                
                while (x >= (temp << 1))
                {
                    temp <<= 1;
                    multiple <<= 1;
                }
                
                x -= temp;
                i += multiple;
            }

            if (sign * i >= INT_MAX)
                return INT_MAX;
            if (sign * i <= INT_MIN)
                return INT_MIN;
            return sign * i;
        }
};