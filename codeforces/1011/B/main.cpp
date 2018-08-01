#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int map[256];
int a[101];
int main()
{
	int n, m, t;
	while (cin >> n >> m)
	{
		memset(map, 0, sizeof(map));
		for (int i = 0; i < m; i++)
		{
			cin >> t;
			map[t] ++;
		}
		int day = 100;
		for (day = 100; day > 0; day--)
		{
			int count = 0;
			for (int type = 0; type <= 100; type++)
			{
				count += map[type] / day;
			}
			if (count >= n)
				break;
		}
		cout << day << endl;
	}
    return 0;
}