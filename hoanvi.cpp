#include <iostream>
using namespace std;
#define MAX 20
#define TRUE 1
#define FALSE 0
int X[MAX];
int n;
int countHV;
int Stop;

void Init()
{
    countHV = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        X[i] = i;
}

void Result()
{
    countHV++;
    for (int i = 1; i <= n; i++)
        cout << X[i] << " ";

    cout << endl;
}

void Next_Permutaion()
{
    int j, k, r, s, temp;
    j = n - 1;
    while (j > 0 && X[j] > X[j + 1])
        j--;

    if (j == 0)
        Stop = TRUE;

    else
    {
        k = n;
        while (X[j] > X[k])
            k--;
        temp = X[j];
        X[j] = X[k];
        X[k] = temp;
        r = j + 1;
        s = n;
        while (r < s)
        {
            temp = X[r];
            X[r] = X[s];
            X[s] = temp;
            r++;
            s--;
        }
    }
}

void Permutation()
{
    Stop = FALSE;
    while (!Stop)
    {
        Result();
        Next_Permutaion();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Init();
    Permutation();
    return 0;
}