class Solution {
    public int removeDuplicates(int[] nums)
    {
        if (nums == null || nums.length == 0)
            return 0;

        int         new_i = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[new_i] != nums[i])
            {
                new_i++;
                nums[new_i] = nums[i];
            }
        }
        return (new_i + 1);
    }
}