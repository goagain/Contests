#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
char s[1100][1100];
bool a[1100][1010];
bool canDraw(int x, int y, int level)
{
    int i = level;
    {
        if(x + i < 0 || x + i >= n)
            return false;
        if(y + i < 0 || y + i >= m)
            return false;
        if(s[x+i][y] == '.')
            return false;
        if(s[x][y+i] == '.')
            return false;
    }
    i = -level;
    {
        if(x + i < 0 || x + i >= n)
            return false;
        if(y + i < 0 || y + i >= m)
            return false;
        if(s[x+i][y] == '.')
            return false;
        if(s[x][y+i] == '.')
            return false;
    }
    // cout << x << " " << y << " " <<  level << endl;
    return true;
}
void Draw(int x, int y, int level)
{
    for (int i = -level; i <= level; i++)
    {
        a[x][y+i] = true;
        a[x+i][y] = true;
    }
}

int ans;
int xx[11000000];
int yy[11000000];
int ll[10100000];

int main(int argc, char const *argv[])
{
    while(cin >> n >> m)
    {
        ans = 0;
        for (int i = 0; i < n; i ++)
        {
            scanf("%s", s[i]);
        }
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j++)
            {
                int level = 0;
                for (level = 0; level <= max(n, m); level++)
                {
                    if(!canDraw(i, j, level))
                        break;
                }

                if(level > 1)
                {
                    Draw(i, j, level -1);
                    xx[ans] = i;
                    yy[ans] = j;
                    ll[ans] = level-1;
                    ans ++;
                }
            }
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j++)
            {
                if(s[i][j] == '*' && a[i][j] == false)
                {
                    ans = -1;
                }
            }
        if (ans == -1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", ans);
            for(int i = 0; i < ans ; i++)
                printf("%d %d %d\n", xx[i]+1, yy[i] +1, ll[i]);
        }
    }
}

