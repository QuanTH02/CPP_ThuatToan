#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int c[100][100];
int n, x[100], visited[100], xopt[100];
int f = (1 << 30) - 1;
int sum = 0, cmin = f;
void init()
{
    cin >> n;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            if (cmin > c[i][j])
                cmin = c[i][j];
        }
    }
}

void Solution()
{
    cout << "Lo trinh toi uu: ";
    cout << xopt[0] << "-->";
    for (int i = 1; i <= 2 * n; i++)
    {
        cout << xopt[i] << "-->";
    }
    cout << xopt[0] << endl;
    cout << "Tong chi phi: " << f;
}
void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            x[k] = i;
            x[k + n] = i + n;
            visited[i] = 1;
            if (k == 1)
                sum += c[0][x[k]] + c[x[k]][x[k] + n];
            else
                sum += c[x[k - 1] + n][x[k]] + c[x[k]][x[k] + n];
            if (k == n)
            {
                int f1 = sum + c[x[k] + n][0];
                if (f1 < f)
                {
                    f = f1;
                    for (int j = 0; j <= 2 * n; j++)
                    {
                        xopt[j] = x[j];
                    }
                }
            }

            else if ((sum + cmin * (2 * (n - k) + 1)) < f)
                Try(k + 1);
            visited[i] = 0;
            sum -= c[x[k - 1] + n][x[k]] + c[x[k]][x[k] + n];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    x[0] = 0;
    Try(1);
    Solution();
}