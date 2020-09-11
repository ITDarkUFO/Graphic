#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;

}

int main()
{
	int n, d, g = 0, x;
	vector<int> a;
	cin >> n >> d;
	for (; n; --n)
	{
		cin >> x;
		if (x%d == 0)
		{
			a.push_back(x);
			g = gcd(g, x);
		}
	}
	if (g == d)
	{
		cout << a.size() << endl;
		for (auto b : a)
			cout << b << " ";
	}
	else
		cout << -1;
	return 0;
}
