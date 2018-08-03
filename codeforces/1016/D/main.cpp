#include <bits/stdc++.h>
using namespace std;

long long n, a[300001][2];
long long sum[300001][2];
long long postSum[300001];
long long ring[300001][2];
int main(int argc, char const *argv[])
{
    while (cin >> n)
    {
        memset(a, 0, sizeof(a));
        memset(ring, 0, sizeof(ring));
        memset(postSum, 0, sizeof(postSum));
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i][0];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i][1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            postSum[i] = postSum[i + 1] + a[i][0] + a[i][1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int flag = 0; flag <= 1; flag++)
            {
                ring[i][flag] = ring[i + 1][flag] + postSum[i + 1] + a[i][!flag] * (2 * (n - i) - 1);

                sum[i][flag] = max(sum[i + 1][!flag] + 2 * postSum[i + 1] + a[i][!flag],
                                   ring[i][flag]);
            }
        }
        cout << sum[0][0] << endl;
    }
    return 0;
}
