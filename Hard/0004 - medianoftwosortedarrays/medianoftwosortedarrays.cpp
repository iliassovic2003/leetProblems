# include <vector>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1,
                vector<int>& nums2)
        {
            vector<int> results;
            int i = 0;
            int j = 0;
            
            while (i < nums1.size() && j < nums2.size())
            {
                if (nums1[i] <= nums2[j])
                    results.push_back(nums1[i++]);
                else
                    results.push_back(nums2[j++]);
            }

            while (i < nums1.size())
                results.push_back(nums1[i++]);
            while (j < nums2.size())
                results.push_back(nums2[j++]);

            if (results.size() % 2 == 0)
                return ((results[results.size() / 2 - 1] + results[results.size() / 2]) / 2.0);
            else
                return results[results.size() / 2];
        }
};