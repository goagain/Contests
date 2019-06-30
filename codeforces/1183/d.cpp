#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;

map<int, int> mmap;
map<int, int> count_map;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        mmap.clear();
        count_map.clear();
        int n;
        scanf("%d", &n);
        vector<int> nums;
        for(int i = 0; i < n; i++)
        {
            int t;
            scanf("%d", &t);
            mmap[t]++;
        }

        for (auto iter : mmap)
        {
            if (iter.second)
            {
                count_map[iter.second] ++;
            }
        }
        count_map[0] = 0;
        long long result = 0;
        int last = -1;
        for (map<int,int>::reverse_iterator iter = count_map.rbegin(); iter != count_map.rend(); iter++)
        {
            int key = iter->first;
            result += key;
            count_map[key] --;
            if (last != -1)
            {
                if (count_map[last] > 0)
                {
                    int upper_bound = last - 1;
                    long long count = min(count_map[last], upper_bound - key);
                    long long lower_bound = upper_bound - count + 1;
                    result += (lower_bound + upper_bound) * count / 2;
                    count_map[key] += (count_map[last] - count);
                }
            }
            last = key;
        }
        printf("%lld\n", result);
    }
}