# include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = 0;
        int start = 0;

        unordered_map<char, int>   mySet;
        for (int i = 0; i < s.length(); i++)
        {
            if (mySet.find(s[i]) != mySet.end())
                start = max(start, mySet[s[i]] + 1);
            
            mySet[s[i]] = i;
            length = max(length, i - start + 1);
        }
        return length;
    }
};