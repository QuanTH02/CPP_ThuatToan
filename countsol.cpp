#include <iostream>
#include <cstring>
using namespace std;
int coeff[100];
int countSol(int n, int rhs)
{
    int dp[rhs + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = coeff[i]; j <= rhs; j++)
        {
            dp[j] += dp[j - coeff[i]];
        }
    }
    return dp[rhs];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> coeff[i];
        m -= coeff[i];
    }

    cout << countSol(n, m);
    return 0;
}