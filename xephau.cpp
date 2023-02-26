#include <iostream>
#include <stdlib.h>
using namespace std;
int n;
int a[100];

void printSolution()
{
    int i;
    for (i = 1; i <= n; i++)
    {
        cout << "(" << i << "," << a[i] << "), ";
    }
    cout << endl;
}

int check(int y, int k)
{
    for (int i = 1; i <= k - 1; i++)
    {
        if (a[i] == y)
            return 0;
        if (abs(a[i] - y) == abs(i - k))
            return 0;
        else
            return 1;
    }
}

void Try(int k)
{
    for (int y = 1; y <= n; y++)
    {

        if (check(y, k) == 1)
        {
            a[k] = y;
            if (k == n)
                printSolution();
            else
                Try(k + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Try(1);
    return 0;
}