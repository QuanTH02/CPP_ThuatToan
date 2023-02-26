#include <bits/stdc++.h>
using namespace std;
int n, k1, k2;
int mem1[1001];
int mem2[1001];
int ans;
void setValue()
{
    for (int i = k1; i <= n; i++)
    {
        if (i == k1)
        {
            mem2[i] = 1;
        }
        else if (i > k1 && i <= k2)
        {
            for (int j = i - k1; j >= 1; j--)
            {
                mem2[i] += mem1[j];
            }
            mem2[i] += 1;
        }
        else
        {
            for (int j = i - k1; j >= i - k2; j--)
            {
                mem2[i] += mem1[j];
            }
        }
        mem1[i] = mem2[i - 1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k1 >> k2;
    memset(mem1, 0, sizeof(mem1));
    memset(mem2, 0, sizeof(mem2));
    mem1[1] = 1;
    if (k1 == 1)
        mem2[1] = 1;
    else
        mem2[1] = 0;
    if (n == k1)
        cout << "1";
    else if (n < k1)
        cout << "0";
    else
    {
        setValue();
        cout << (mem1[n] + mem2[n]);
    }
}