#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string s1, s2;
    while (cin >> n)
    {
        int m = ceil(sqrt(n));

        for (int i = 0; i * m <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int v = (i + 1) * m - j;
                if (v <= n)
                    printf("%d ", v);
            }
        }
        // for (int i = n; i > n / 2; i--)
        //     printf("%d ", i);
        puts("");
    }
    /* code */
    return 0;
}
