#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int t;
    int myscore = 0;
    int rank = 1;
    for (int j = 0; j < 4; j++)
    {
        cin >> t;
        myscore += t;
    }
    for (int i = 2; i <= n; i++)
    {
        int score = 0;
        for (int j = 0; j < 4; j++)
        {
            cin >> t;
            score += t;
        }
        if (score > myscore)
        {
            rank++;
        }
    }
    cout << rank << endl;
    /* code */
    return 0;
}
