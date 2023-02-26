#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
const int maxN = 999 + 100;
const int oo = 1e9 + 7;
int a[maxN][maxN], d[maxN][maxN];
int m, n, r, c;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<ii> qe;

int solve()
{
    qe.push(ii(r - 1, c - 1));
    d[r - 1][c - 1] = 1;
    a[r - 1][c - 1] = 1;
    while (!qe.empty())
    {
        ii u = qe.front();
        qe.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if ((x < 1 || x >= n || y < 1 || y >= m) && a[x][y] == 0)
                return d[u.first][u.second] + 1;
            if (a[x][y] != 1)
            {
                d[x][y] = d[u.first][u.second] + 1;
                qe.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = solve();
    cout << ans << endl;
}