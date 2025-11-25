# include <string>
# include <stack>
using namespace std;

class Solution {
    public:
        bool isValid(string s)
        {
            stack<char> stack;

            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                    stack.push(s[i]);
                else {
                    if (stack.empty())
                        return false;

                    char top = stack.top();
                    if ((s[i] == ')' && top == '(') ||
                        (s[i] == '}' && top == '{') ||
                        (s[i] == ']' && top == '['))
                            stack.pop();
                    else
                        return false;
                }
            }

            return stack.empty();
        }
};