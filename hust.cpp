#include <iostream>
int x[10], a[10], visit[10];
int n, k, target, cnt = 0;
using namespace std;
void check()
{
    int b = a[1] * 100 + a[2] * 10 + a[3] - (a[4] * 100 + 62) + (a[5] * 1000 + a[6] * 100 + a[7] * 10 + a[3]);
    if (b == target)
        cnt++;
}

bool UCV(int y, int k)
{
    int i;
    for (i = 1; i <= k - 1; i++)
        if (y == x[i])
            return false;
    return true;
}

void Try1(int i)
{
    for (int j = 1; j <= k; j++)
    {
        if (visit[x[j]] == false)
        {
            visit[x[j]] = true;
            a[i] = x[j];
            if (i == k)
                check();
            else
                Try1(i + 1);
            visit[x[j]] = false;
        }
    }
}

void Try(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if (i == k)
            Try1(1);
        else
            Try(i + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    n = 9;
    k = 7;
    x[0] = 0;
    cin >> target;
    for (int i = 1; i <= n; i++)
        visit[i] = false;
    Try(1);
    cout << cnt;
    return 0;
}