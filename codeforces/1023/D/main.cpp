#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> a;
bool hasZero = false;
bool allAreZero = true;
int lastNonZero = 1;
int firstZero = 0;

int l[1000000];
int r[1000000];
template <typename T, typename Compare = std::less<T>>
class RMQ
{
  public:
    vector<vector<int>> st;
    function<bool (T, T)> cmp;

    RMQ(vector<T> array)
    {
        cmp = Compare();
        size_t size = array.size();
        int k = log2(size);
        st.push_back(array);
        for (int k = 1; (1 << k) < size; k++)
        {
            vector<T> tmp = vector<T>(size);
            for (size_t i = 0; i < tmp.size(); i++)
            {
                int rIndex = min(i + (1 << (k - 1)), size);
                tmp[i] = cmp(st[k - 1][i], st[k - 1][rIndex]) ? st[k - 1][i] : st[k - 1][rIndex];
            }
            st.push_back(move(tmp));
        }
    }

    T query(size_t l, size_t r)
    {
        int k = log2(r - l);
        if (cmp(st[k][l], st[k][r - (1 << k)]))
            return st[k][l];
        else
            return st[k][r - (1 << k)];
    }
};
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
    RMQ<int> rmq(a);
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
            if (r[x] - 1 < l[x] + 1)
                continue;
            if (rmq.query(l[x] + 1, r[x]) < x)
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