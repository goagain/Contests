#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, k;
    while(cin>>n>>m)
    {
        vector<int> a(1000);
        vector<int> ans;
        int l, r;
        for(int i = 0; i< n ;i ++)
        {
            cin >> l >> r;
            for (int j = l; j <= r; j++)
            {
                a[j] = 1;
            }
        }
        for(int j = 1; j <=m ; j ++)
        {
            if (a[j] == 0)
            {
                ans.push_back(j);
            }
        }
        cout << ans.size() << endl;
        for(int j = 0; j < ans.size() ; j ++)
        {
            cout << ans[j] << endl;
        }
    }
    return 0;
}
