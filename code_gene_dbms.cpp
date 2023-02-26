#include <bits/stdc++.h>
using namespace std;
int n, L;

void gene(string a)
{
    int k = a.length();
    for (int i = 0; i < L - k; i++)
    {
        a = '0' + a;
    }
    cout << a << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a;
    cin >> n >> L;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        gene(a);
    }
}