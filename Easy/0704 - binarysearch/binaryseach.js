var search = function(nums, target)
{
    let start = 0;   
    let end = nums.length;

    while (start < end)
    {
        let median = Math.floor(start + (end - start) / 2);
        if (target < nums[median])
            end = median;
        else if (target > nums[median])
            start = median + 1;
        else
            return median;
    }

    return -1;
};