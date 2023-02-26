#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
const int64_t N_INF = INF * (-1);
int n;
int64_t mem1[1000000];
int64_t mem2[1000000];
vector<int64_t> v;
int64_t ans = N_INF;
void setValue()
{
    int64_t res = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            if (mem1[i - 1] != N_INF)
            {
                if (mem1[i - 1] > 0)
                    mem1[i] = mem1[i - 1] + v[i];
                else
                    mem1[i] = v[i];
            }
            else
            {
                mem1[i] = v[i];
            }
            if (mem1[i - 1] != N_INF)
            {
                mem2[i] = mem2[i - 1] + v[i];
            }
            else
            {
                mem2[i] = N_INF;
            }
        }
        else
        {
            if (mem2[i - 1 != N_INF])
            {
                mem1[i] = mem2[i - 1] + v[i];
            }
            else
            {
                mem1[i] = N_INF;
            }
            if (mem1[i - 1] != N_INF)
            {
                if (mem1[i - 1] > 0)
                    mem2[i] = mem1[i - 1] + v[i];
                else
                    mem2[i] = v[i];
            }
            else
            {
                mem2[i] = v[i];
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    if (v[0] % 2 != 0)
    {
        mem1[0] = N_INF;
        mem2[0] = v[0];
    }
    else
    {
        mem1[0] = v[0];
        mem2[0] = N_INF;
    }
    setValue();
    int64_t *it;
    it = max_element(mem1 + 1, mem1 + n);

    cout << *it;
}