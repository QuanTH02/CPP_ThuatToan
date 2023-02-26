#include <iostream>
#include <algorithm>
using namespace std;
const int N_MAX = 100000;
int n;

typedef struct
{
    int start;
    int finish;
} Time;
Time a[N_MAX];
Time b[N_MAX];
bool cmp(Time A, Time B)
{
    if (A.finish < B.finish)
        return true;
    if (A.finish == B.finish)
    {
        if (A.start < B.start)
            return true;
    }

    return false;
}

void Solution()
{
    int last = 0;
    b[0] = a[0];

    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i].start >= a[last].finish)
        {
            b[res] = a[i];
            ++res;

            last = i;
        }
    }
    cout << res << endl;
    for (int i = 0; i < res; i++)
    {
        cout << b[i].start << " - " << b[i].finish << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].start >> a[i].finish;
    }
    sort(a, a + n, cmp);
    Solution();
    return 0;
}