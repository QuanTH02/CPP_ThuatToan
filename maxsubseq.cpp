#include <iostream>
#include <cstring>
using namespace std;
const int maxN = 1000000;
int a[maxN];
int mem[maxN];
bool comp[maxN];

int max_sum(int i)
{
    if (i == 1)
        return a[i];
    if (comp[i])
        return mem[i];
    int res = max(a[i], a[i] + max_sum(i - 1));
    mem[i] = res;
    comp[i] = true;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(comp, 0, sizeof(comp));
    int n, maximum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    max_sum(n);
    for (int i = 1; i <= n; i++)
    {
        maximum = max(maximum, mem[i]);
    }
    cout << maximum;
    return 0;
}