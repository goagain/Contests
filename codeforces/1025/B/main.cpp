// import math
// n = int(input())
// p = []
// for i in range(n):
//     t = input().split()
//     a, b = int(t[0]), int(t[1])
//     p.append((a,b))

// gcd = 0
// for (a, b) in p:
//     lcm = a * b // math.gcd(a, b)
//     if gcd == 0:
//         gcd = lcm
//     gcd = math.gcd(lcm, gcd)

// if gcd == 1:
//     print(-1)
//     exit()
// else:
//     for i in range(2, int(math.sqrt(gcd) + 1)):
//         if gcd % i == 0:
//             print(i)
//             exit()
// print(gcd)
#include <bits/stdc++.h>
using namespace std;
const int max_prime = 100007;
bitset<max_prime> not_prime;
vector<int> realPrime;
void process_prime()
{
    for (int i = 2; i < max_prime; i++)
    {
        if (not_prime[i] == false)
        {
            realPrime.push_back(i);
            for (long long j = i; i * j < max_prime; j++)
            {
                not_prime[i * j] = true;
            }
        }
    }
}

bool isPrime(int n)
{
    return !not_prime[n];
}

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, b % a);
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main(int argc, char const *argv[])
{
    process_prime();
    // for(int i = 0; i < realPrime.size(); i++)
    //     printf("%d ", realPrime[i]);
    int n;
    scanf("%d", &n);
    map<int, int> m;

    int p1, p2;
    scanf("%d%d", &p1, &p2);
    for (int i = 0; i < realPrime.size(); i++)
    {
        if (p1 % realPrime[i] == 0)
        {
            m[realPrime[i]] = 1;
            while (p1 % realPrime[i] == 0)
            {
                p1 /= realPrime[i];
            }
        }
        if (p2 % realPrime[i] == 0)
        {
            m[realPrime[i]] = 1;
            while (p2 % realPrime[i] == 0)
            {
                p2 /= realPrime[i];
            }
        }
    }
    if (p1 != 1)
        m[p1] = 1;
    if (p2 != 1)
        m[p2] = 1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &p1, &p2);
        for (auto &k : m)
        {
            if (k.second != 0 && p1 % k.first != 0 && p2 % k.first != 0)
            {
                k.second = 0;
            }
        }
    }

    for (auto &k : m)
    {
        if (k.second)
        {
            cout << k.first << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
