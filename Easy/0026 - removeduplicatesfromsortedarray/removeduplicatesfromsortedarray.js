var removeDuplicates = function(nums) {
    if (nums.empty)
        return 0;

    let         new_i = 0;

    for (let i = 1; i < nums.length; i++)
    {
        if (nums[new_i] != nums[i])
        {
            new_i++;
            nums[new_i] = nums[i];
        }
    }
    return (new_i + 1);
};