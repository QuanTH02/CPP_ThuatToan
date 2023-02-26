#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    // your code

    for (int i = 0; i < a.size(); i++)
    {
        int h = a[i] * a[i];
        if (count(a.begin(), a.end(), a[i]) != count(b.begin(), b.end(), h))
            return false;
    }
    return true;
}
int main()
{
    vector<int> a = {121, 144, 19, 161, 19, 144, 19, 11};
    vector<int> b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
    cout << comp(a, b);
}
