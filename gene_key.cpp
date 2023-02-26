#include <bits/stdc++.h>
using namespace std;
int n, L, m;
vector<int> v;
void init()
{
    string s;
    int a;
    cin >> n >> L >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a = stoi(s);
        v.push_back(a);
    }
}

void Solution()
{
    int i = 1;
    while (m > 0)
    {
        if (count(v.begin(), v.end(), i) == 0)
        {
            v.push_back(i);
            m--;
        }
        i++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        string s = to_string(v[i]);
        while (s.length() < L)
        {
            s = '0' + s;
        }
        cout << s << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    Solution();
    return 0;
}