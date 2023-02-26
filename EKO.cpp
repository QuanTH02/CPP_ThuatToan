
#include <algorithm>
#include <iostream>
using namespace std;
int n, m, h, height[1000000];
int maxheight = 0;
void init()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> height[i];
		maxheight = max(height[i], maxheight);
	}
	int sum = 0;
}

int totalwood(int d)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (height[i] >= d)
			sum += height[i] - d;
	}
	return sum;
}

int Solution()
{
	int l = 0, r = maxheight, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (totalwood(mid) == m)
			return mid;
		else if (totalwood(mid) > m)
		{
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	cout << Solution();
}