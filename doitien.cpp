#include <bits/stdc++.h>
using namespace std;

void Cashier(int X, int c[], int n, int S[])
{
    for (int i = n - 1; i >= 0; i--)
    {
        int soluong = X / c[i];
        if (soluong > 0)
            S[i] = soluong;
        X = X % c[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c[] = {1, 5, 10, 25, 100};
    int n = 5, X;
    int S[5] = {0};
    cin >> X;
    Cashier(X, c, n, S);
    cout << "Cach doi " << X << " cent: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (S[i] > 0)
        {
            cout << S[i] << " dong xu menh gia " << c[i] << endl;
        }
    }
    return 0;
}