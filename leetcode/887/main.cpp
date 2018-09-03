#include <bits/stdc++.h>
using namespace std;

int a[101][10001];
class Solution
{
  public:
    int f(int n, int m)
    {
        if (m == 0)
            return 0;
        if (n == 0)
            return 0;
        if (a[n][m])
            return a[n][m];
        return a[n][m] = 1 + f(n - 1, m - 1) + f(n, m - 1);
    }
    int superEggDrop(int K, int N)
    {
        for (int i = 1; i <= N; i++)
        {
            if (f(K, i) >= N)
                return i;
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    int n, k;
    while (cin >> n >> k)
        cout << solution.superEggDrop(n, k) << endl;
    return 0;
}
