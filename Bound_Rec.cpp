#include <bits/stdc++.h>
using namespace std;
int n, xmin = 1001, xmax = 0, ymin = 1001, ymax = 0, x, y, x2, y2;
int min(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> x2 >> y2;
        if (xmin > min(x, x2))
            xmin = min(x, x2);
        if (ymin > min(y, y2))
            ymin = min(y, y2);
        if (xmax < max(x, x2))
            xmax = max(x, x2);
        if (ymax < max(y, y2))
            ymax = max(y, y2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << ((xmax - xmin) * (ymax - ymin));
}