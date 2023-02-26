#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "";
    int n;
    cin >> n;

    for (int i = 0; i < pow(2, n); i++)
    {
        for (int m = 0; m < n; m++)
        {
            s += "0";
        }
        for (int j = 0; j < n; j++)
        {
            if ((i / int(pow(2, j))) % 2 == 1)
                s[n - j - 1] = '1';
        }
        cout << s << "\n";
        s = "";
    }
    return 0;
}