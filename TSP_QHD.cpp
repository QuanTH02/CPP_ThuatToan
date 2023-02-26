#include <bits/stdc++.h>
using namespace std;
int n, c[20][20];
int mem[20][1 << 20];
void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
}

int tsp(int k, int visited)
{
    if (visited == ((1 << n) - 1))
    {
        return c[k][0];
    }
    if (mem[k][visited] != INT_MAX)
    {
        return mem[k][visited];
    }
    int minTSPk = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (i == k || (visited & (1 << i)))
            continue;
        int distance = c[k][i] + tsp(i, visited | (1 << i));
        if (distance < minTSPk)
        {
            minTSPk = distance;
        }
    }
    mem[k][visited] = minTSPk;
    return minTSPk;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << tsp(0, 1 << 0);
}