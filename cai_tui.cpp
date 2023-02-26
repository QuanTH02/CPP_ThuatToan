#include <bits/stdc++.h>
using namespace std;
int n, L;
int w[1000], v[1000];
int mem[1000][1000];
void init()
{
    cin >> n >> L;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }
}

void Value()
{
    for (int i = 0; i <= n; i++)
    {
        for (int s = 0; s <= L; s++)
        {
            if (i == 0 || s == 0)
                mem[i][s] = 0;
            if (s < w[i])
                mem[i][s] = mem[i - 1][s];
            else
                mem[i][s] = max(v[i] + mem[i - 1][s - w[i]], mem[i - 1][s]);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    memset(mem, -1, sizeof(mem));
    Value();
    cout << mem[n][L];
    return 0;
}