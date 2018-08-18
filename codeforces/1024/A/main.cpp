#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        int len;
        string s;
        cin >> len >> s;
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (abs(s[i] - s[len - i - 1]) != 2 && s[i] != s[len - i - 1])
                flag = false;
        }
        puts(flag ? "YES" : "NO");
    }
}
