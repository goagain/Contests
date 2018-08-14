#include <bits/stdc++.h>
using namespace std;

vector<long long> square;
int main()
{
    long long n;
    cin >> n;
    for (long long i = 1; i < 65536; i += 2)
    {
        long long t = i * i;
        while (t <= UINT_MAX)
        {
            square.push_back(t);
            t = t * 2;
        }
    }
    sort(square.begin(), square.end());
    while (cin >> n)
    {
        bool flag = false;
        for (int i = 0; square[i] <= n; i++)
            flag = !flag;
        cout << (int)flag << endl;
    }
    return 0;
}