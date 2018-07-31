#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n, k, s;
    while(cin >> n >> k >> s)
    {
        long long p = s / k;
        if(p == 0 || k * (n-1) < s)
        {
            cout << "NO" << endl;
            continue;
        }
        if (p * k < s)
            p++;
        // cout << "p=" << p << endl;
        {
            cout << "YES" << endl;
            long long remain = s;
            long long r = p + 1;
            long long l = 1;
            bool flag = true;
            long long pos;
            for(int i = 1; i <= k ; i++)
            {
                if(i % 2 == 1)
                {
                    if ((r-l - 1) * (k-i+1) >= remain && flag)
                    {
                        r --;
                        flag = false;
                        // cout << "r minus" << endl;
                    }
                    if (remain > r - l)
                    {
                        cout << r << " ";
                        remain -= r - l;
                    }
                    else
                    {
                        cout << l + remain << " ";
                    }
                }
                else
                {
                    if ((r-l - 1) * (k-i+1) >= remain && flag)
                    {
                        l++;
                        flag = false;
                        // cout << "r minus" << endl;
                    }
                    if (remain > r - l)
                    {
                        cout << l << " ";
                        remain -= r - l;
                    }
                    else
                    {
                        // cout << "-------" << remain << endl;
                        cout << r - remain << " ";
                    }

                }
            }
        }
        cout << endl;
    }
    return 0;
}

