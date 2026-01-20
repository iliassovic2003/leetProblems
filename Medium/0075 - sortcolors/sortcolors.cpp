#include <vector>
using namespace std;

class Solution {
    public:
        void sortColors(vector<int>& nums)
        {
            int index0 = 0;
            int len = nums.size();
            int index2 = len - 1;
            int temp;

            int i = 0;
            while (i < len && i <= index2)
            {
                if (nums[i] == 0)
                {
                    if (index0 < i)
                    {
                        temp = nums[index0];
                        nums[index0] = 0;
                        nums[i] = temp;
                    } 
                    index0++;
                    i++;
                }
                else if (nums[i] == 2)
                {
                    temp = nums[index2];
                    nums[index2] = 2;
                    nums[i] = temp;
                    index2--;
                }
                else
                    i++;
            }
        }
};