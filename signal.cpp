#include <iostream>
#include <algorithm>
using namespace std;
int n, A[1000001], cnt = 0;
void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
}

void Solution()
{
    for (int i = 2; i < n; i++)
    {
        if ((A[i] > A[i - 1]) && (A[i] > A[i + 1]))
        {
            cnt++;
        }
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    Solution();
}