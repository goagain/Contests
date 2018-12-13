#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
// for n in sys.stdin:
//     n = int(n)
//     a = [int(x) for x in sys.stdin.readline().split()]
//     allsum = sum(a)
//     tsum = 0
//     for index, x in enumerate(a):
//         tsum += x
//         if tsum * 2 >= allsum:
//             print(index + 1) 
//             break
    int n;
    while (cin >> n)
    {
        vector<int> a;
        int t;
        while(n--)
        {
            cin >> t;
            a.push_back(t);
        }
        int sum = 0;
        for (int i:a)
            sum += i;
        int tsum = 0;
        for (int i = 0; i < a.size(); i++)
        {
            tsum += a[i];
            if (tsum * 2 >= sum)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
