#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, query;
    while (~scanf("%d%d%d", &n, &m, &query))
    {
        int ans[10000];
        memset(ans, 0, sizeof(ans));
        string s;
        string p;
        cin >> s >> p;
        for (int i = 1; i <= s.length(); i++)
        {
            ans[i] = ans[i - 1];

            int find = s.find(p, i - 1);
            if (find == i - 1)
            {
                ans[i] += 1;
            }
        }
        int l, r;
        while(query--)
        {
            scanf("%d%d", &l, &r);
            if(r - l + 1 >= m)
            {
                printf("%d\n", ans[r - m + 1] - ans[l - 1]);
            }
            else
            {
                puts("0");
            }
        }
    }
    return 0;
}
