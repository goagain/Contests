#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i ++)
        {
            vector<int>visited(n+1);
            int cur = i;
            while(visited[cur] == 0)
            {
                visited[cur] = 1;
                cur = a[cur];
            }
            printf("%d ", cur);
        }
        puts("");
    }
    /* code */
    return 0;
}
