#include <bits/stdc++.h>
using namespace std;
int n, t, d;
vector<int> a;
vector<int> t1;
int mem[101][1000];

void setValue()
{
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (t1[j] > i)
                mem[i][j] = 0;
            else if (t1[j] == i)
                mem[i][j] = a[j];
            else
            {
                int *it;
                if (j == 0)
                    mem[i][j] = a[j];
                else
                {
                    if (j < d)
                        it = max_element(mem[i - t1[j]], mem[i - t1[j]] + j);
                    else
                        it = max_element(mem[i - t1[j]] + j - d, mem[i - t1[j]] + j);
                    mem[i][j] = a[j] + *it;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> n >> t >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        a.push_back(k);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        t1.push_back(k);
    }
    memset(mem, 0, sizeof(mem));
    setValue();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (ans < mem[i][j])
                ans = mem[i][j];
        }
    }
    cout << ans;
}