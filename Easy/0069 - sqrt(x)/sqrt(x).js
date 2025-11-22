var mySqrt = function(x) {
    if (x == 0)
        return 0;
    if (x < 4)
        return 1;

    let result;

    let start = 2;
    let end = Math.floor(x / 2);

    while (start <= end) 
    {
        let median = Math.floor(start + (end - start) / 2);

        if (median <= Math.floor(x / median))
        {
            result = median;
            start = median + 1;
        }
        else
            end = median - 1;
    }
    return result;
};