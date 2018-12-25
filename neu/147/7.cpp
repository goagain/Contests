#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
struct Matrix
{
    long long a00, a01, a10, a11;
    Matrix operator+(const Matrix& o) const
    {
        Matrix ans;
        ans.a00 = (a00 + o.a00) % MOD;
        ans.a01 = (a01 + o.a01) % MOD;
        ans.a10 = (a10 + o.a10) % MOD;
        ans.a11 = (a11 + o.a11) % MOD;
        return ans;
    }
    Matrix operator*(const Matrix& o) const
    {
        Matrix ans;
        ans.a00 = (a00 * o.a00 + a01 * o.a10) % MOD;
        ans.a01 = (a00 * o.a01 + a01 * o.a11) % MOD;
        ans.a10 = (a10 * o.a00 + a11 * o.a10) % MOD;
        ans.a11 = (a10 * o.a01 + a11 * o.a11) % MOD;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    long long n;
    while(~scanf("%lld", &n))
    {
        Matrix m;
        m.a00 = 1;
        m.a10 = 1;
        m.a01 = 0;
        m.a11 = 0;
        Matrix base;
        base.a00 = 1;
        base.a01 = 2;
        base.a10 = 1;
        base.a11 = 1;
        long long x = n;
        // Matrix temp = m;
        // for(int i = 0; i < n ; i++)
        // {
        //     temp = base * temp;
        // }
        x--;
        while(x > 0)
        {
            if (x % 2 == 1)
            {
                m = base * m;
            }
            base = base * base;
            x /= 2;
        }
        long long t = m.a00;
        // cout << t << endl;
        long long t2 = t * t % MOD;
        if (n % 2 == 1)
        {
            long long ans = t2  * (t2 + 1) / 2 % MOD;
            printf("%lld\n", ans);
        }
        else
        {
            long long ans = t2  * (t2 - 1) / 2 % MOD;
            printf("%lld\n", ans);
        }
    }
    /* code */
    return 0;
}