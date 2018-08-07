#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> numMap {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    vector<string> ans;
    string tmp;
    void dfs(const string &digits, int ith)
    {
        if (ith == digits.length() && ith != 0)
        {
            ans.push_back(tmp);
            return;
        }
        int num = digits[ith] - '0';
        for (int j = 0; j < numMap[num].length(); j++)
        {
            tmp[ith] = numMap[num][j];
            dfs(digits, ith + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        tmp = digits;
        ans = vector<string>();
        dfs(digits, 0);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution().letterCombinations("23");
    Solution().letterCombinations("9");
    system("pause");
    /* code */
    return 0;
}
