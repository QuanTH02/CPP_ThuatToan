#include <iostream>
#include <algorithm>
using namespace std;
int test, n, c;
const int N_MAX = 100000;
int T[20];
int A[N_MAX];
int dem = 0;

bool check(int mid)
{
    int cnt = 1, last = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] >= (A[last] + mid))
        {
            cnt++;
            last = i;
        }
    }
    if (cnt >= c)
        return true;
    else
        return false;
}

void Solution()
{
    int l = 0, r = int((A[n - 1] - A[0]) / (c - 1)), mid, res = 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid) == true)
        {
            l = mid + 1;
            res = mid;
        }
        else
            r = mid - 1;
    }
    T[dem] = res;
    dem++;
}

void input()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    Solution();
}

void init()
{
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        input();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    for (int i = 0; i < dem; i++)
    {
        cout << T[i] << endl;
    }
    return 0;
}