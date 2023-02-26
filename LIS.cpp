#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, mem[10000], a[10000];
void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

int ls(int i)
{
    if (mem[i] != -1)
        return mem[i];
    int res = 1;
    for (int j = 1; j < n; j++)
    {
        if (a[i] < a[j])
            res = max(res, 1 + ls(j));
    }
    mem[i] = res;
    return res;
}

void trace(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (a[j] < a[i] && mem[j] == 1 + mem[i])
        {
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    memset(mem, -1, sizeof(mem));
    ls(n);
    int res = *max_element(mem, mem + n);
    cout << res << endl;
    trace(res);
}