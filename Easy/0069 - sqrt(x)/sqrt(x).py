class Solution:
    def mySqrt(self, x: int) -> int:
        if (x == 0) :
            return 0
        if (x < 4) :
            return 1

        result = 0

        start = 2
        end = int(x / 2)

        while (start <= end) :
            median = int(start + (end - start) / 2)

            if (median <= int(x / median)) :
                result = median
                start = median + 1
            else :
                end = median - 1
        return int(result)