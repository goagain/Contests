#include <iostream>
#include <cmath>
#include <algorithm>
#include <memory>
#include <cstring>
using namespace std;

int a[1000100];

int main(int argc, char const *argv[])
{
	int n, m;
	while (cin >> n >> m)
	{
		int t;
		int mod = 0;
		int written = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			written = (mod + t) / m;
			mod = (mod + t) % m;
			cout << written << ' ' ;
		}
	}
	return 0;
}