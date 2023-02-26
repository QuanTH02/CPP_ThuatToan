#include <iostream>
#include <vector>
using namespace std;
int n, m, res;
int a[10][30];
vector<int> T[10];
bool conflict[30][30];
int load[10], x[30];
void init()
{
    int k1, k2, c, d, e;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> k1;
        for (int j = 1; j <= k1; j++)
        {
            cin >> c;
            T[c].push_back(i);
        }
    }
    cin >> k2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            conflict[i][j] = false;
        }
    }
    for (int i = 1; i <= k2; i++)
    {
        cin >> d >> e;
        conflict[d][e] = true;
        conflict[e][d] = true;
    }
}

bool check(int t, int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (conflict[i][k] && x[i] == t)
            return false;
    }
}

void solution()
{
}

void Try(int k)
{
    for (int i = 0; i < T[k].size(); i++)
    {
        int t = T[k][i];
        if (check(t, k))
        {
            x[k] = t;
            load[t] += 1;
            if (k == n)
                solution();
            else
            {
                if (load[t] < res)
                    Try(k + 1);
            }
            load[t]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    for (int t = 1; t <= m; t++)
        load[t] = 0;
    res = 1e9;
    Try(1);

    return 0;
}