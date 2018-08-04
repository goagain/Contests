#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        map<int, int> m;
        vector<vector<int>> ans;
        for (auto i : nums)
            m[i]++;
        for (auto iter = m.begin(); iter != m.end(); iter++)
        {
            iter->second--;
            for(auto iter2 = m.begin(); iter2 != m.end(); iter2++)
            {
                if(iter2->second > 0)
                {
                    iter2->second --;
                    int remain = -iter->first - iter2->first;
                    auto iter3 = m.find(remain);

                    if (iter3 != m.end())
                    {
                        if(iter3->second > 0)
                        {
                            if (iter->first <= iter2->first && iter2->first <= iter3->first)
                                ans.push_back(vector<int>{iter->first, iter2->first, iter3->first});
                        }
                    }
                    iter2->second ++;
                }
            }
            iter->second++;
        }
        return ans;
    }
};