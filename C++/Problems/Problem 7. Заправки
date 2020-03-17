#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int n, to, min_price, output_price = 0;
vector<int> price, d;
vector<bool> marks;
vector<vector<int>> paths;

int D(int s, int f)
{
	for (int i = 0; i < n; i++)
	{
		min_price = INT_MAX, to = -1;
		for (int j = 0; j < n; j++)
		{
			if ((!marks[j]) && (paths[i][j] < min_price))
				min_price = paths[i][j];
				
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, fp, sp, start = 1, finish = 5;
	cin >> n;
	price.resize(n);
	marks.resize(n);
	paths.resize(n, vector<int>());
	for (int i = 0; i < n; i++)
		cin >> price[i];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> fp >> sp;
		paths[fp - 1].push_back(sp - 1);
		paths[sp - 1].push_back(fp - 1);
	}
	
	int output = D(start - 1, finish - 1);

	if (output != -1)
			cout << output;
	else
		cout << -1;
	return 0;
}
