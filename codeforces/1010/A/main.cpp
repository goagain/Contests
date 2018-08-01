#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[10001], b[10001];
int main()
{
	int payload, planetCount;
	while (~scanf("%d%d", &planetCount, &payload))
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < planetCount; i++)
			scanf("%d" ,a + i);
		for (int i = 0; i < planetCount; i++)
			scanf("%d", b + i);
		a[planetCount] = a[0];
		b[planetCount] = b[0];
		double l = 0, r = 2e10;
		double m;
		while (abs(r - l) > 1e-6)
		{
			m = (l + r) / 2;
			bool can = true;
			double fuel = m;
			for (int i = 0; i < planetCount; i++)
			{
				double weight = fuel + payload;
				double used = weight / a[i];
				fuel -= used;
				if (fuel < 0)
				{
					can = false;
					break;
				}
				weight = fuel + payload;
				used = weight / b[i+1];
				fuel -= used;
				if (fuel < 0)
				{
					can = false;
					break;
				}
			}
			if (can)
				r = m;
			else
				l = m;
		}
		if (l > 1e10)
			cout << -1 << endl;
		else
			printf("%.7f\n", l);
	}
    return 0;
}