#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> next(s.length(), -1);
        stack<int> stack;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                stack.push(i);
            }
            else
            {
                if (!stack.empty())
                {
                    int top = stack.top();
                    next[top] = i;
                    stack.pop();
                }
            }
        }
        int index = 0;
        int ans = 0;
        int maxAns = 0;
        while(index != s.length())
        {
            if (next[index] != -1)
            {
                ans += next[index] - index + 1;
                index = next[index] + 1;
                if (ans > maxAns)
                    maxAns = ans;
            }
            else
            {
                index ++;
                ans = 0;
            }
        }
        return maxAns;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.longestValidParentheses("(()") << endl;
    cout << solution.longestValidParentheses("()(()") << endl;
    return 0;
}
