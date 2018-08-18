#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (~scanf("%d", &n))
    {
        vector<int> c(n + 1);
        vector<int> a(n + 1);
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &c[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        int totalCost = 0;
        int currentIndex = 1;
        for(currentIndex = 1; currentIndex <= n; currentIndex++)
        {
            int color = currentIndex;
            if (v[currentIndex])
                continue;
            int tIndex = currentIndex;
            while(true)
            {
                if (v[tIndex] == 0)
                {
                    v[tIndex] = color;
                    tIndex = a[tIndex];
                    continue;
                }
                if (v[tIndex] != color)
                    break;
                int minAmount = c[tIndex];
                int t2 = a[tIndex];
                while(t2 != tIndex)
                {
                    minAmount = min(minAmount, c[t2]);
                    t2 = a[t2];
                }
                totalCost += minAmount;
                break;
            }
        }
        printf("%d\n", totalCost);
    }
}
