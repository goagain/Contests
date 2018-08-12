#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int parent[3001];
    int hate[3001];
    int findParent(int x)
    {
        return parent[x] == x ? x : parent[x] = findParent(parent[x]);
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(int i = 1; i <= N; i ++)
            parent[i] = i;
        memset(hate, 0, sizeof(hate));
        for(auto t: dislikes)
        {
            int a = t[0], b = t[1];
            if (findParent(a) != findParent(b))
            {
                findParent
            }
            t[0], t[1];
        }

    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}
