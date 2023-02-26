#include <bits/stdc++.h>
using namespace std;
int coeff[100];
int n, m, f;
int t[100], X[100];
int cnt = 0;

void Solution()
{
    if (f == m)
    {
        cnt++;
    }
}

void Try(int k)
{
    int v;
    for (v = 1; v <= (m - f - (t[n] - t[k])) / coeff[k]; v++)
    {
        X[k] = v;
        f += coeff[k] * X[k];
        if (k == n)
        {
            Solution();
        }
        else
        {
            Try(k + 1);
        }
        f -= coeff[k] * X[k];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> coeff[i];
    }
    t[1] = coeff[2];
    for (int i = 2; i <= n; i++)
    {
        t[i] = t[i - 1] + coeff[i];
    }

    Try(1);
    cout << cnt;
    return 0;
}