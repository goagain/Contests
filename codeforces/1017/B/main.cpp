#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string s1, s2;
    while (cin >> n >> s1 >> s2)
    {
        long long bothZero = 0;
        long long bothOne = 0;
        long long AIsZero = 0;
        long long BIsZero = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == '0' && s2[i] == '0')
                bothZero ++;
            else if (s1[i] == '0' && s2[i] == '1')
                AIsZero ++;
            if (s1[i] == '1' && s2[i] == '1')
                bothOne ++;
            else if (s1[i] == '1' && s2[i] == '0')
                BIsZero ++;
        }
        cout << bothZero * (bothOne + BIsZero) + AIsZero * BIsZero << endl ;
    }
    /* code */
    return 0;
}
