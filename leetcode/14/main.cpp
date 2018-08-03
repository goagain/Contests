#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string &s = strs[0];
        int i = 0;
        for(i = 0; i < s.length(); i++)
        {
            char c = s[i];
            for (int j = 1; j < strs.size(); j++)
            {
                string& t = strs[j];
                if (t.length() == i || t[i] != c)
                {
                    goto ret;
                }
            }
        }
        ret:
            return s.substr(0, i);
    }
};
int main(int argc, char const *argv[])
{
    cout << "Hello world" << endl;
    return 0;
}
