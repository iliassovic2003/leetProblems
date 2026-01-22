class Solution {
    public int[] getConcatenation(int[] nums) {
        int         size = nums.length;
        int[]       result;

        result = new int[2 * size];
        
        System.arraycopy(nums, 0, result, 0, size);
        System.arraycopy(nums, 0, result, size, size);

        return result;
    }
}