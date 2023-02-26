#include <bits/stdc++.h>
using namespace std;
int n, L1, L2;
int store[1000001];
int mem[1000001];
void init()
{
    cin >> n >> L1 >> L2;
    for (int i = 0; i < n; i++)
    {
        cin >> store[i];
    }
}
void setValue()
{
    mem[0] = store[0];
    int res = 0;
    int *it;
    for (int i = 1; i < n; i++)
    {
        if (i < L1)
            res = max(store[i], mem[i - 1]);
        else if (i < L2)
        {
            it = max_element(mem, mem + i - L1 + 1);
            res = max(store[i] + *it, mem[i - 1]);
        }
        else
        {
            it = max_element(mem + i - L2, mem + i - L1 + 1);
            res = max(store[i] + *it, mem[i - 1]);
        }
        mem[i] = res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(mem, 0, sizeof(mem));
    init();
    setValue();
    cout << mem[n - 1];
}