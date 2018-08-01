#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int map[256];
int main()
{
	int len, n;
	string s;
	cin >> len >> n >> s;
	for (int i = 0; i < s.length(); i++)
	{
		map[s[i]] = 1;
	}
	int last = 0;
	int weight = 0;
	for (int i = 0; i < 256 && n; i++)
	{
		if (map[i] == 1 && i - last >= 2)
		{
			weight += i - 'a' + 1;
			last = i;
			n--;
		}
	}
	if (n == 0)
		cout << weight << endl;
	else
		cout << -1 << endl;
    return 0;
}