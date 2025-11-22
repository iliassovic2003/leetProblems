class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return x;

        int result;

        int start = 1;
        int end = x;

        while (start <= end) 
        {
            int median = start + (end - start) / 2;

            if (median <= x / median)
            {
                result = median;
                start = median + 1;
            }
            else
                end = median - 1;
        }
        return result;
    }
};