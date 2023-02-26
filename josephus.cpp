#include <bits/stdc++.h>
using namespace std;

vector<int> josephus(vector<int> items, int k)
{
    vector<int> a;
    int n = items.size();
    int i = k - 1;
    while (n > 0)
    {
        if (i >= n)
        {
            i = i % n;
        }
        a.push_back(items[i]);
        items.erase(items.begin() + i);
        n--;
        i += k - 1;
    }
    return a;
}

int main()
{
    vector<int> a = josephus({0, 1, 2, 3}, 6);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
}