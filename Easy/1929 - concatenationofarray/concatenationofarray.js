var getConcatenation = function(nums) {
    const         size = nums.length;
    const         result = new Array(2 * size);

    let i = -1;
    while (++i < size)
    {
        result[i] = nums[i];
        result[i + size] = nums[i];
    } 
    return result;
};