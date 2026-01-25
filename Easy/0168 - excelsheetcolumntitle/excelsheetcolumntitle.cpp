#include <string>
using namespace std;

class Solution {
    public:
        string convertToTitle(int columnNumber)
        {
            string result = "";
            int reps;
            int remainder;
            
            while (columnNumber > 0)
            {
                reps = columnNumber / 26;
                remainder = columnNumber % 26;
                
                if (remainder == 0) {
                    result = 'Z' + result;
                    columnNumber = reps - 1;
                }
                else {
                    result = char('A' + remainder - 1) + result;
                    columnNumber = reps;
                }
            }
            
            return result;
        }
};