#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	if (x % y == 0)
		return y;
	return gcd(y, x%y);
}

int main()
{
	int n, base, t;
	while (cin >> n >> base)
	{
		bool isPrime = true;
		int g = base;
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			g = gcd(g, t);
		}
		cout << base / g << endl;
		for (int i = 0; i*g < base; i++)
			cout << i * g << endl;
	}
	return 0;
}