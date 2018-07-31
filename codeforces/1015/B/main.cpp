#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(int len, string& s, string& t)
{
    vector<int> ans;
    vector<int> countS(26);
    vector<int> countT(26);
    for(int i = 0; i <s.length(); i++)
    {
        countS[s[i]-'a'] ++;
        countT[t[i]-'a'] ++;
    }
    for(int i = 0; i <26;i++)
    {
        if(countS[i] != countT[i])
        {
            cout << -1 << endl;
            return;
        }
    }

    for(int i = 0; i < len; i++)
    {
        int index = i;
        for( ; index < len && s[index] != t[i]; index++);
            // cout << s[i] << t[index] << " ";
        // cout << index << endl;
        for(int j = index - 1; j >= i; j--)
        {
            swap(s[j], s[j+1]);
            ans.push_back(j+1);
        }
        // cout << s << " " << t << endl;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    int len;
    string s, t;
    while(cin>>len>>s>>t)
    {
        solve(len, s, t);
    }
    return 0;
}

