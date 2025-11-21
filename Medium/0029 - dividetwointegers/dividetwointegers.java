class Solution {
    public int divide(int dividend, int divisor)
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
            long result = sign * x;

            if (result > Integer.MAX_VALUE)
                return Integer.MAX_VALUE;
            if (result < Integer.MIN_VALUE)
                return Integer.MIN_VALUE;
            return (int)result;
        }

        while (x >= y)
        {
            long temp = y;
            long multiple = 1;
            
            while (x >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            
            x -= temp;
            i += multiple;
        }

        long result = sign * i;

        if (result > Integer.MAX_VALUE)
            return Integer.MAX_VALUE;
        if (result < Integer.MIN_VALUE)
            return Integer.MIN_VALUE;
        return (int)result;
    }
}