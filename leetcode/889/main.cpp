#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int R, C;
    bool isValidPos(int y, int x)
    {
        return (y >= 0 && y < R) && x >= 0 && x < C;
    }
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0)
    {
        this->R = R;
        this->C = C;
        vector<vector<int>> ans;
        int curX = c0;
        int curY = r0;
        int curStep = 0;
        int totalStep = 1;
        int direct = 1;
        while (ans.size() < R * C)
        {
            if(isValidPos(curY, curX))
                printf("%d %d\n", curY, curX);
            if (direct == 1)
            {
                if (isValidPos(curY, curX))
                    ans.push_back(vector<int>{curY, curX});
                curX ++;
                curStep ++;
                if (curStep == totalStep)
                {
                    curStep = 0;
                    direct ++;
                }
            }
            else if (direct == 2)
            {
                if (isValidPos(curY, curX))
                    ans.push_back(vector<int>{curY, curX});
                curY ++;
                curStep ++;
                if (curStep == totalStep)
                {
                    curStep = 0;
                    totalStep ++;
                    direct ++;
                }
            }
            else if (direct == 3)
            {
                if (isValidPos(curY, curX))
                    ans.push_back(vector<int>{curY, curX});
                curX --;
                curStep ++;
                if (curStep == totalStep)
                {
                    curStep = 0;
                    direct ++;
                }
            }
            else if (direct == 4)
            {
                if (isValidPos(curY, curX))
                    ans.push_back(vector<int>{curY, curX});
                curY --;
                curStep ++;
                if (curStep == totalStep)
                {
                    curStep = 0;
                    totalStep ++;
                    direct  = 1;
                }
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    solution.spiralMatrixIII(5, 6, 1, 4);
    return 0;
}
