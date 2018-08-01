#include <iostream>
#include <cmath>
#include <algorithm>
#include <memory>
#include <cstring>
using namespace std;

int a[1000100];

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		memset(a, -1, sizeof(a));
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + 2 * n);
		long long l = a[0], r = a[n - 1];
		long long u = a[n], d = a[2 * n - 1];
		long long ans = (r - l) * (d - u);
		
		long long width = d - l;
		for (int i = 1; i <= n-1; i++)
		{
			long long height = a[i + n - 1] - a[i];
			if (ans > width*height)
				ans = width * height;
		}
		cout << ans << endl;
	}
	return 0;
}