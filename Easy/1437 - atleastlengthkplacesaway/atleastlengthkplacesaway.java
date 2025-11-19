class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int j = k;

        for (int i = 0; i < nums.length; i++)
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
    }
}