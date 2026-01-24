var hammingWeight = function(n) {
    let ans = 0;

    while (n)
    {
        if (n % 2)
            ans++;
        n = Math.floor(n / 2);
    }
    return ans;
};