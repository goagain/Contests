#include <iostream>
#include <cmath>
#include <algorithm>
#include <memory>
#include <cstring>
using namespace std;

int a[100010];
int d[100010];
int main(int argc, char const *argv[])
{
	int n, x, t;
	while (cin >> n >> x)
	{
		int ans = -1;
		bool hasSame = false;
		memset(a, -1, sizeof(a));
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			if (d[t])
				hasSame = true;
			d[t] = 1;
			
			int afterMod = t & x;
			int div;
			if ((t & x) == t)
				div = 0;
			else
				div = 1;
			if (a[afterMod] == -1)
			{
				a[afterMod] = div;
			}
			else
			{
				if (ans == -1 || ans > a[afterMod] + div)
				{
					ans = a[afterMod] + div;
				}
				if (div < a[afterMod])
					a[afterMod] = div;
			}
		}
		if (hasSame)
			cout << 0 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}