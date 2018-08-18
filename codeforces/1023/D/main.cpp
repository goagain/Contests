#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> a;
bool hasZero = false;
bool allAreZero = true;
int lastNonZero = 1;
int firstZero = 0;

int rmq[32][1000000];
int l[1000000];
int r[1000000];
int query(int l, int r)
{
    if (l > r)
        return q + 1;
    int k = log2(r - l + 1);
    return min(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        a.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            if (allAreZero)
            {
                for (int j = 0; j < i; j++)
                {
                    a[j] = a[i];
                }
            }
            allAreZero = false;
            lastNonZero = a[i];
        }
        else
        {
            hasZero = true;
            firstZero = i;
            if (!allAreZero)
            {
                a[i] = lastNonZero;
            }
        }
    }
    if (allAreZero)
    {
        puts("YES");
        for (int i = 0; i < n; i++)
            printf("%d ", q);
        return 0;
    }
    for (int i = 0; i < n; i++)
        rmq[0][i] = a[i];
    for (int k = 1; k < log2(n) + 1; k++)
    {
        for (int i = 0; i < n; i++)
        {
            int rIndex = min(i + (1 << (k - 1)), n - 1);
            rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][rIndex]);
        }
    }
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    for (int i = 0; i < n; i++)
    {
        int t = a[i];
        if (l[t] == -1)
            l[t] = i;
        r[t] = i;
    }
    for (int x = 1; x <= q; x++)
    {
        if (l[x] != -1)
        {
            if (query(l[x] + 1, r[x] - 1) < x)
            {
                puts("NO");
                return 0;
            }
        }
    }
    if (l[q] == -1)
    {
        if (!hasZero)
        {
            puts("NO");
            return 0;
        }
        else
        {
            a[firstZero] = q;
        }
    }
    puts("YES");
    for(int t: a) printf("%d ", t);
    return 0;
}