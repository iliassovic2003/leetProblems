var reverse = function(x) {
    const INT_MIN = -Math.pow(2, 31);
    const INT_MAX = Math.pow(2, 31) - 1;

    let result = 0;
    let temp;
    while (x != 0)
    {
        temp = x % 10;
        x = Math.trunc(x / 10);
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && temp > 7))
            return 0;
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && temp < -8))
            return 0;
        result = result * 10 + temp;
    }
    return result;
};