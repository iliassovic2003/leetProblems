class Solution {
    public int findFinalValue(int[] nums, int original)
    {
        int j = nums.length - 1;
        Boolean found = true;

        while (found)
        {
            found = false;
            for (int i = 0; i <= j; i++)
            {
                if (nums[i] == original)
                {
                    original *= 2;
                    nums[i] = nums[j];
                    found = true;
                    j--;
                    break;
                }
            }
        }
        return (original);
    }
}