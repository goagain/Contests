#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

struct State
{
    int step;
    int x;
    int y;
    int removed[12];
};
int n, m;
int a[22][22];
State q[1000001];
int queueStart = 0;
int queueEnd = 0;
bool isStone(int x, int y, const int* removed)
{
    if(a[x][y] == 1)
    {
        for(int i = 0; i < 12; i++) 
        {
            if(removed[i] == 10000 * x + 100 * y + 1)
                return false;
        }
        return true;
    }
    return false;
}

bool process(const State &state)
{
    int step = state.step;
    if (step > 10)
        return false;
    int x = state.x;
    int y = state.y;
    const int* removed = state.removed;

    if (x > 0 && !isStone(x - 1, y, removed))
    {
        int curX = x - 1;
        int curY = y;
        while (curX >= 0)
        {
            if (a[curX][curY] == 3)
            {
                return true;
            }
            if (isStone(curX, curY, removed))
            {
                State newState= state;
                newState.step = step + 1;
                newState.removed[step] = (curX * 10000 + curY * 100 + 1);
                newState.x = curX + 1;
                q[queueEnd++] = newState;
                break;
            }
            curX--;
        }
    }
    if (x < m - 1 && !isStone(x + 1, y, removed))
    {
        int curX = x + 1;
        int curY = y;
        while (curX < m)
        {
            if (a[curX][curY] == 3)
            {
                return true;
            }
            if (isStone(curX, curY, removed))
            {
                State newState= state;
                newState.step = step + 1;
                newState.removed[step] = (curX * 10000 + curY * 100 + 1);
                newState.x = curX - 1;
                q[queueEnd++] = newState;
                break;
            }
            curX++;
        }
    }
    if (y > 0 && !isStone(x, y - 1, removed))
    {
        int curX = x;
        int curY = y - 1;
        while (curY >= 0)
        {
            if (a[curX][curY] == 3)
            {
                return true;
            }
            if (isStone(curX, curY, removed))
            {
                State newState= state;
                newState.step = step + 1;
                newState.removed[step] = (curX * 10000 + curY * 100 + 1);
                newState.y = curY + 1;
                q[queueEnd++] = newState;
                break;
            }
            curY--;
        }
    }
    if (y < n - 1 && !isStone(x, y + 1, removed))
    {
        int curX = x;
        int curY = y + 1;
        while (curY < n)
        {
            if (a[curX][curY] == 3)
            {
                return true;
            }
            if (isStone(curX, curY, removed))
            {
                State newState= state;
                newState.step = step + 1;
                newState.removed[step] = (curX * 10000 + curY * 100 + 1);
                newState.y = curY - 1;
                q[queueEnd++] = newState;
                break;
            }
            curY++;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &n, &m) && n != 0 && m != 0)
    {
        memset(a, 0, sizeof(a));
        queueStart = 0;
        queueEnd = 0;
        int x, y;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
                if (a[i][j] == 2)
                {
                    x = i;
                    y = j;
                }
            }
        }
        State init;
        init.step = 1;
        init.x = x;
        init.y = y;

        q[queueEnd++] = init;
        bool finded = false;
        while(queueStart < queueEnd)
        {
            State &front = q[queueStart];
            queueStart++;
            if (process(front))
            {
                cout << front.step << endl;
                finded = true;
                break;
            }
        }
        if (!finded)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}