
#include <bits/stdc++.h>
using namespace std;
int mem[10000][10000];
int n, m;
int a[10000], b[10000];

void init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
}

int lcs(int i, int j)
{
    if (i == -1 || j == -1)
    {
        return 0;
    }
    if (mem[i][j] != -1)
        return mem[i][j];
    int res = 0;
    if (a[i] == b[j])
        res = max(res, 1 + lcs(i - 1, j - 1));
    else
    {
        res = max(res, lcs(i - 1, j));
        res = max(res, lcs(i, j - 1));
    }
    mem[i][j] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    memset(mem, -1, sizeof(mem));
    cout << lcs(n - 1, m - 1);
}
