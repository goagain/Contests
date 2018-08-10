#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return vector<int>();
        }
        sort(nums.begin(), nums.end());
        vector<int> prevNode(nums.size());
        for (int i = 0; i < prevNode.size(); i++)
            prevNode[i] = -1;
        vector<int> seqLength(nums.size(), 1);

        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int t = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] % nums[i] == 0)
                {
                    if (seqLength[i] + 1 > seqLength[j])
                    {
                        prevNode[j] = i;
                        seqLength[j] = seqLength[i] + 1;
                        if (seqLength[j] > seqLength[maxIndex])
                        {
                            maxIndex = j;
                        }
                    }
                }
            }
        }
        vector<int> ans;
        int index = maxIndex;
        do
        {
            ans.push_back(nums[index]);
            index = prevNode[index];
        } while(-1 != index);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> test {1,2,3};
    cout << solution.largestDivisibleSubset(test).size() << endl;
    return 0;
}
