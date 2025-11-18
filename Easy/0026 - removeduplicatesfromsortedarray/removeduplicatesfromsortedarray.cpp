#include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums)
        {
            if (nums.empty())
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
};