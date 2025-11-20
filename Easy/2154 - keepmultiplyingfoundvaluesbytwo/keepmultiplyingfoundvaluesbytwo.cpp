#include <vector>
using namespace std;

class Solution {
    public:
        int findFinalValue(vector<int>& nums, int original)
        {
            int j = nums.size() - 1;
            bool found = true;

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
};