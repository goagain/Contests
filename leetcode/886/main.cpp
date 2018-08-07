#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    struct Edge
    {
        int nodes;
        int edgeNumber;
    };
    static Edge edge[3010][3010];
    static int l[30100];
    static int r[30100];
    static int visited[30100];
    static int rem[30010];
    int M;
    int N;
    vector<vector<int>> edges;
    void dp(int pos, int remain)
    {
        printf("pos %d remain %d \n", pos, remain);
        if (visited[pos])
            return;
        rem[pos] = remain;
        visited[pos] = 1;

        for (int i = 0; i < N; i++)
        {
            Edge &e = edge[i][pos];
            if (e.edgeNumber != -1)
            {
                int edgeNumber = e.edgeNumber;
                int nodes = e.nodes;
                if (pos < i)
                {
                    if (remain >= nodes)
                    {
                        l[edgeNumber] = nodes;
                        rem[i] = max(rem[i], remain - nodes - 1);
                        // dp(i, remain - nodes - 1);
                    }
                    else
                    {
                        l[edgeNumber] = max(l[edgeNumber], remain);
                    }
                }
                else
                {
                    if (remain >= nodes)
                    {
                        r[edgeNumber] = nodes;
                        rem[i] = max(rem[i], remain - nodes - 1);
                        // dp(i, remain - nodes - 1);
                    }
                    else
                    {
                        r[edgeNumber] = max(r[edgeNumber], remain);
                    }
                }
            }
        }
        int maxRemain = 0;
        int nextPos = -1;

        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && rem[i] > maxRemain)
            {
                maxRemain = rem[i];
                nextPos = i;
            }
        }
        if (nextPos != -1)
            dp(nextPos, maxRemain);
    }

    int reachableNodes(vector<vector<int>> &edges, int M, int N)
    {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(visited, 0, sizeof(visited));
        memset(rem, -1, sizeof(visited));
        memset(edge, -1, sizeof(edge));
        this->edges = edges;
        this->M = M;
        this->N = N;
        for (int i = 0; i < edges.size(); i++)
        {
            auto &tmpEdge = edges[i];
            Edge e;
            e.nodes = tmpEdge[2];
            e.edgeNumber = i;
            edge[tmpEdge[0]][tmpEdge[1]] = e;
            edge[tmpEdge[1]][tmpEdge[0]] = e;
        }
        dp(0, M);
        int ans = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            ans += min(l[i] + r[i], edges[i][2]);
        }
        for (int i = 0; i < N; i++)
        {
            if (rem[i] >= 0)
                ans++;
        }
        return ans;
    }
};
Solution::Edge Solution::edge[3010][3010];
int Solution::l[30100];
int Solution::r[30100];
int Solution::visited[30100];
int Solution::rem[30010];

int main(int argc, char const *argv[])
{
    Solution *solution = new Solution();
    vector<vector<int>> v{
        {0, 1, 10}, {0, 2, 1}, {1, 2, 2}};
    cout << solution->reachableNodes(v, 6, 3) << endl;
    return 0;
}
