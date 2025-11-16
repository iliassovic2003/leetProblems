#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int x = s.length(), y = p.length();
        std::vector<std::vector<bool>> arr(x + 1, std::vector<bool>(y + 1, false));
        
        arr[0][0] = true;                   //  typical empty string

        for (int i = 2; i <= y; i++)        //  empty string with a sequence of *chars
            if (p[i - 1] == '*')
                arr[0][i] = arr[0][i - 2];

        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (p[j - 1] == '*')        //  zero or more matches
                    arr[i][j] = arr[i][j - 2] || (arr[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                else                        //  simple since there is no *
                    arr[i][j] = arr[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }

        return arr[x][y];
    }
};