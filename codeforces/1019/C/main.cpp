#include <bits/stdc++.h>
using namespace std;

vector<int> q[3011];
int n, m;

long long enums(int votes)
{
    long long cost = 0;
    int my = q[1].size();
    vector<int> ptr(m + 1);
    vector<int> remain;
    for (int i = 2; i <= m; i++)
    {
        while (q[i].size() - ptr[i] >= votes)
        {
            cost += q[i][ptr[i]];
            ptr[i]++;
            my ++;
            if (my > votes)
            {
                return LLONG_MAX;
            }
        }
        for (int j = ptr[i]; j < q[i].size(); j++)
        {
            remain.push_back(q[i][j]);
        }
    }
    sort(remain.begin(), remain.end(), greater<int>());
    for (int i = my; i < votes; i++)
    {
        if (remain.empty())
            return LLONG_MAX;
        cost += remain.back();
        remain.pop_back();
    }
    return cost;
}

int main(int argc, char const *argv[])
{
    while (cin >> n >> m)
    {
        for (int i = 0; i <= m; i++)
            q[i].clear();
        for (int i = 0; i < n; i++)
        {
            int vote, money;
            cin >> vote >> money;
            q[vote].push_back(money);
        }
        for (int i = 2; i <= m; i++)
        {
            sort(q[i].begin(), q[i].end());
        }
        long long minCost = LLONG_MAX;
        for (int i = 1; i <= (n/2) + 1; i++)
        {
            minCost = min(minCost, enums(i));
        }
        cout << minCost << endl;
    }
    /* code */
    return 0;
}
