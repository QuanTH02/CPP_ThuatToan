#include <bits/stdc++.h>
using namespace std;

int INF = 999999;
int d[10];
int mem[10][10000];

int opt(int i, int x)
{
    if (x < 0)
        return INF;
    if (x == 0)
        return 0;
    if (i == -1)
        return INF;
    if (mem[i][x] != -1)
        return mem[i][x];
    int res = INF;
    res = min(res, 1 + opt(i, x - d[i]));
    res = min(res, opt(i - 1, x));

    mem[i][x] = res;
    return res;
}

void trace(int i, int x)
{
    if (x < 0 || x == 0 || i == -1)
        return;
    int res = INF;
    if (mem[i][x] == 1 + opt(i, x - d[i]))
    {
        cout << d[i] << " ";
        trace(i, x - d[i]);
    }
    else
    {
        trace(i - 1, x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(mem, -1, sizeof(mem));
    int n, X, cnt;
    cin >> n >> X;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    cout << "Cach doi " << X << " cent: " << endl;
    cnt = opt(n - 1, X);
    trace(n - 1, X);
    return 0;
}