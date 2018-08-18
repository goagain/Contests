#include <bits/stdc++.h>
using namespace std;

long long get(long long n, long long x, long long y)
{
    long long ans = 0;
    if (x % 2 == 1)
    {
        ans += (x / 2) * n;
    }
    else
    {
        ans += ((x - 1) / 2) * n + (n + 1) / 2;
    }
    if ((x + y) % 2 == 0)
    {
        ans += (y + 1) / 2;
    }
    else
    {
        ans += (y + 1) / 2 + (n * n) / 2;
        if (n % 2 == 1 && x % 2 == 1)
            ans ++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    long long n, q;
    cin >> n >> q;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         printf("%d ", get(n, i, j));
    //     }
    //     puts("");
    // }
    while (q--)
    {
        long long x, y;
        cin >> x >> y;
        cout << get(n, x, y) << endl;
    }
}
