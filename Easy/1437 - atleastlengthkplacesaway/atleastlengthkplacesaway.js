var kLengthApart = function(nums, k) {
    let j = k;

    for (let i = 0; i < nums.length; i++)
    {
        if (nums[i] == 1)
        {
            if (j < k)
                return false;
            j = 0;
        }
        else
            j++;
    }
    return true;
};