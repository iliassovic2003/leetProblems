var divide = function(dividend, divisor)
{
    const INT_MAX = 2147483647;
    const INT_MIN = -2147483648;

    let i = 0;
    let x = dividend;
    let y = divisor;

    let sign = 1;

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
        let temp = y;
        let multiple = 1;
        
        while (x >= (temp << 1) && (temp << 1) > 0) // js have serious problems with bits-manip/overflow
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
};