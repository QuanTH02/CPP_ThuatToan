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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
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
    for (int i = 1; i <= n; i++)
    {
        cout << xopt[i] << "-->";
    }
    cout << xopt[1] << endl;
    cout << "Tong chi phi: " << f;
}
void Try(int k)
{
    for (int i = 2; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            x[k] = i;
            visited[i] = 1;
            sum += c[x[k - 1]][x[k]];
            if (k == n)
            {
                int f1 = sum + c[x[k]][x[1]];
                if (f1 < f)
                {
                    f = f1;
                    for (int j = 1; j <= n; j++)
                    {
                        xopt[j] = x[j];
                    }
                }
            }

            else if ((sum + cmin * (n - k + 1)) < f)
                Try(k + 1);
            visited[i] = 0;
            sum -= c[x[k - 1]][x[k]];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    x[1] = 1;
    Try(2);
    Solution();
}