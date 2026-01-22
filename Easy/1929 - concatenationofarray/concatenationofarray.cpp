class Solution {
    public:
        vector<int> getConcatenation(vector<int>& nums) {
            int         size = nums.size();
            vector<int> result(2 * size);

            for (int i = 0; i < size; i++)
            {
                result[i] = nums[i];
                result[i + size] = nums[i];
            } 
            return result;
        }
};