#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, t1 = 0, t2 = 0;
	int t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		t1 += t;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		t2 += t;
	}
	if (t1 >= t2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}