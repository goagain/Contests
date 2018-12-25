#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
int numbers[10000000];

int main(int argc, char const *argv[])
{
    for (int i = 2; i < 10000000; i++)
    {
        if(numbers[i] == 0)
        {
            prime.push_back(i);
            for(int j = i * 2; j < 10000000; j += i)
            {
                numbers[j] = 1;
            }
        }
    }

    int T, n;
    cin >> T;
    while(T--)
    {
        scanf("%d", &n);
        int l = 0, r = prime.size();
        while(l < r)
        {
            int m = (l + r) / 2;
            if (prime[m] <= n)
                l = m + 1;
            else
                r = m;
        }
        printf("YES\n");
        printf("%d\n", prime[l - 1]);
    }
}