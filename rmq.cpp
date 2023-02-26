#include <iostream>
#include <math.h>
using namespace std;
const int MAXN = 1000000;
const int LOGMAXN = 20;
int A[MAXN];
int M[MAXN][LOGMAXN];
void process2(int N)
{
    int i, j;
    for (i = 0; i < N; i++)
        M[i][0] = i;
    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, ans = 0, rmq;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    process2(n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        int length = b - a + 1;
        int k = (int)(log(length) / log(2));
        if (A[M[a][k]] <= A[M[b - (1 << k) + 1][k]])
            rmq = M[a][k];
        else
            rmq = M[b - (1 << k) + 1][k];
        ans += A[rmq];
    }
    cout << ans << endl;
    return 0;
}