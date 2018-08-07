#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    struct cmp
    {
        bool operator()(const vector<int> &v1, const vector<int> &v2)
        {
            for (int i = 0; i < 4; i++)
            {
                if (v1[i] != v2[i])
                    return v1[i] < v2[i];
            }
            return false;
        }
    };
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>, cmp> s;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int head = j + 1, tail = nums.size() - 1;
                while (tail > head)
                {
                    int sum = nums[i] + nums[j] + nums[head] + nums[tail] - target;
                    if (sum == 0)
                    {
                        auto t = vector<int>{nums[i], nums[j], nums[head], nums[tail]};
                        s.insert(t);
                        head++;
                        tail--;
                    }
                    else if (sum > 0)
                    {
                        tail--;
                    }
                    else
                    {
                        head++;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto quadruplets : s)
            ans.push_back(quadruplets);

        return ans;
    }
};
int main(int argc, char const *argv[])
{
    system("pause");
    /* code */
    return 0;
}
