#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int ans = 0;
        vector<int> horizonal(grid.size());
        vector<int> vertical(grid[0].size());

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] != 0)
                    ans++;
                if (grid[i][j] > horizonal[i])
                    horizonal[i] = grid[i][j];
                if (grid[i][j] > vertical[j])
                    vertical[j] = grid[i][j];
            }
        }
        for (int val: horizonal) ans += val;
        for (int val: vertical) ans += val;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}
