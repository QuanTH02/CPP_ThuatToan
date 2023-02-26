#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, M, cnt = 0;
void init()
{
    int a;
    cin >> n >> M;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
}

void Solution()
{
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        int res = M - *it;
        if (find(it + 1, v.end(), res) != v.end())
        {
            cnt++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    Solution();
    cout << cnt;
}