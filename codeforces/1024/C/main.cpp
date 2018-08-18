#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        map<int, int> m;
        int t;
        while (n--)
        {
            scanf("%d", &t);
            m[t]++;
        }
        int last = 0;
        int minL, minR;
        double minP = 1000000;
        for (auto &iter:m)
        {
            int edge = iter.first;
            int count = iter.second;
            if (count >= 4)
            {
                int c = (edge + edge);
                double s = edge * edge;
                minP = c * c / s;
                minL = edge;
                minR = edge;
                break;
            }
            else if (count >= 2)
            {
                if (last == 0)
                    last = edge;
                else
                {
                    int c = (edge + last);
                    double s = edge * last;
                    if (c * c / s < minP)
                    {
                        minP = c * c / s;
                        minL = edge;
                        minR = last;
                    }
                    last = edge;
                }
            }
        }
        printf("%d %d %d %d\n", minR, minR, minL, minL);
    }
}
