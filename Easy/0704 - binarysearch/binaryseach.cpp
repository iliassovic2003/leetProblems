#include <vector>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target)
        {
            int start = 0;   
            int end = nums.size();

            while (start < end)
            {
                int median = start + (end - start) / 2;
                if (target < nums[median])
                    end = median;
                else if (target > nums[median])
                    start = median + 1;
                else
                    return median;
            }

            return -1;
        }
};
