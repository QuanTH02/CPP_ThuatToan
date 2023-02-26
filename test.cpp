#include <bits/stdc++.h>
using namespace std;
int M, n, a[100], T = 0;
void input()
{
    cin >> n;
    cin >> M;
}
void solution()
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int check(int k, int v)
{
    if (k < n)
        return 1;
    else
        return T + v == M;
}
void Try(int k)
{
    for (int i = 1; i <= M - T - n + k; i++)
    {
        if (check(k, i))
        {
            a[k] = i;
            T += i;
            if (k == n)
                solution();
            else
                Try(k + 1);
            T = T - i;
        }
    }
}
int main()
{
    input();
    Try(1);
    return 0;
}