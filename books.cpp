#include <iostream>
#include <algorithm>
using namespace std;
const int NMAX = 100000;
int n, time[NMAX], sum[NMAX], limit;

void init()
{
    cin >> n >> limit;
    cin >> time[1];
    sum[1] = time[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> time[i];
        sum[i] = sum[i - 1] + time[i];
    }
}

int binary_search(int a[], int l, int r, int t)
{
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == t)
            return mid;
        else if (a[mid] < t)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return r;
}

void Solution()
{
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = binary_search(sum, i, n, limit + sum[i] - time[i]);
        result = max(result, j - i + 1);
    }
    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    Solution();
}