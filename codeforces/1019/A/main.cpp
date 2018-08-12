#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n, h, a, b, k;
    while (cin >> n >> h >> a >> b >> k)
    {
        while(k--)
        {
            int ta, fa, tb, fb;
            cin >> ta >> fa >> tb >> fb;
            int ans = 0;
            ans += abs(ta - tb);
            if (ta == tb)
            {
                ans += abs(fa - fb);
            }
            else
            {
                if (fa > b && fb > b)
                {
                    ans += (fa-b) + (fb-b);
                }
                else if(fa < a && fb < a)
                {
                    ans += (a - fa) + (a - fb);
                }
                else
                {
                    ans += abs(fa - fb);
                }
            }
            cout << ans << endl;
        }
    }
    /* code */
    return 0;
}
