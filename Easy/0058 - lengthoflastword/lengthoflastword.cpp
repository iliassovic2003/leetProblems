#include <string>

class Solution {
    public:
        int lengthOfLastWord(std::string s)
        {
            int     k = 0;
            bool    flag = 0;

            for (int i = s.size() - 1; i >= 0; i--)
            {
                if (s[i] == ' ' && !flag)
                    continue;
                if (s[i] != ' ')
                {
                    if (!flag)
                        flag = 1;
                    k++;
                }
                else
                    break;
            }

            return k;
        }
};