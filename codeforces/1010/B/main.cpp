#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int sequence[1000];
int main()
{
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cout << 1 << endl;
		fflush(stdout);
		cin >> sequence[i];
		if (sequence[i] == 0)
			exit(0);
	}
	int l = 2, r = m;
	int t;
	for (int i = 0; i < 30; i++)
	{
		int mid = (l + r) / 2;
		cout << mid << endl;
		fflush(stdout);
		cin >> t;
		if (t == 0)
		{
			exit(0);
		}
		if (t == sequence[i % n])
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return 0;
}