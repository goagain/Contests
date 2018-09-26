#include <bits/stdc++.h>
using namespace std;

long long f(long long n, long long m)
{
    // cout << n << " " << m << endl;
    if (m < 0)
        return 0;
    if (n < 0)
        return 0;
    if (n == 1 && m == 0)
        return 1;
    if (m == 0)
        return n * f(n - 1, m);

    return (m - 1) * f(n - 1, m - 2) + (n - m) * f(n - 1, m - 1);
}

int main(int argc, char const *argv[])
{
    int n, m;
    while (cin >> n)
    {
        cout << f(n, n) << endl;
    }
    return 0;
}
