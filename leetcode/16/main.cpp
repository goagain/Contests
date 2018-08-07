#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int head = i + 1;
            int tail = nums.size() - 1;
            while (tail > head)
            {
                int sum = nums[i] + nums[head] + nums[tail];
                if(abs(closest - target) > abs(sum - target))
                {
                    closest = sum;
                }
                // printf("%d %d %d %d\n", nums[i], nums[head], nums[tail], sum);
                if (sum - target > 0)
                {
                    tail--;
                }
                else
                {
                    head++;
                }
            }
        }
        return closest;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    /* code */
    return 0;
}
