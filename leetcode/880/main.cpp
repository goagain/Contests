#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string decodeAtIndex(string S, int K)
    {
        vector<long long> mul(S.length() + 1, 1);
        vector<long long> index(S.length() + 1);
        string tmp;

        int pos = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (isalpha(S[i]))
            {
                if (i == 0)
                {
                    index[pos] = 1;
                }
                else
                {
                    index[pos] = index[pos - 1] * mul[pos - 1] + 1;
                }
                tmp += S[i];
                pos++;
            }
            else
            {
                long long multiple = S[i] - '0';
                mul[pos - 1] *= multiple;
            }
        }
        int i = tmp.length() - 1;
        while (i >= 0)
        {
            K = K % index[i];
            if (K == 0)
            {
                return string({tmp[i]});
            }

            i--;
        }
        return "0";
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.decodeAtIndex("leet2code3", 10) << endl;
    cout << solution.decodeAtIndex("ha22", 5) << endl;
    cout << solution.decodeAtIndex("a2345678999999999999999", 1) << endl;

    return 0;
}
