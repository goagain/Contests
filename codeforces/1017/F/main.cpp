#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e8;

int i2n(int i)
{
    if (i % 2 == 0)
    {
        return 6 * (i / 2) + 5;
    }
    else
    {
        return 6 * (i / 2) + 7;
    }
}

int n2i(int n)
{
    if (n % 6 == 5)
    {
        return (n - 5) / 6 * 2;
    }
    else if (n % 6 == 1)
    {
        return (n - 7) / 6 * 2 + 1;
    }
    return -1;
}

long long a, b, c, d;
long long func(int n)
{
    return a * n * n * n + b * n * n + c * n + d;
}

const int maxPrime = 3e8;
bitset<maxPrime / 3> prime;
int main(int argc, char const *argv[])
{
    prime.flip();
    for (int i = 0; i < prime.size(); i++)
    {
        if (n2i(i2n(i)) != i)
            throw new exception();
        if (prime[i])
        {
            // prime_set.insert(i);
            for (long long j = i2n(i); j * i2n(i) < maxPrime; j += 2)
            {
                int nn = n2i(j * i2n(i));
                if (nn != -1 && nn < prime.size())
                    prime[nn] = false;
            }
        }
    }
    // for (int i = 0; i < prime.size(); i++)
    // {
    //     if (prime[i])
    //     {
    //         int p = i2n(i);

    //         printf("%d ", p);
    //     }
    // }
    int n;
    while (cin >> n >> a >> b >> c >> d)
    {
        long long ans = 0;
        {
            int p = 2;
            int t = n;
            while (t > 0)
            {
                t /= p;
                ans += func(p) * t;
            }
        }
        {
            int p = 3;
            int t = n;
            while (t > 0)
            {
                t /= p;
                ans += func(p) * t;
            }
        }
        for (int i = 0; i < prime.size(); i++)
        {
            if (prime[i])
            {
                int p = i2n(i);
                if (p > n)
                    break;
                int t = n;
                while (t > 0)
                {
                    t /= p;
                    ans += func(p) * t;
                }
            }
        }
        cout << (unsigned int)ans << endl;
    }
    /* code */
    return 0;
}
