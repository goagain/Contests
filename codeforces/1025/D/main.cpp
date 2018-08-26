#include <bits/stdc++.h>
using namespace std;

const int max_prime = 1000000000;
bitset<max_prime> not_prime;
vector<int> realPrime;
void process_prime()
{
    realPrime.push_back(2);
    for (int i = 3; i < max_prime; i+=2)
    {
        if (not_prime[i] == false)
        {
            realPrime.push_back(i);
            for (long long j = i; i * j < max_prime; j+=2)
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

int main()
{
    process_prime();
    freopen("out2.txt", "w", stdout);
    printf("700\n");
    for (int i = realPrime.size()-1; i >= realPrime.size()-700; i--)
    {
        printf("%d ", 2 * realPrime[i]);
    }
}