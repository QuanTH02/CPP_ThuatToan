#include <bits/stdc++.h>
using namespace std;

int countStr(string s1, string s2)
{
    int index;
    int count = 0;
    while ((index = s2.find(s1)) != string::npos)
    {
        s2.replace(index, s1.length(), " ");
        count++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    cout << countStr(str1, str2);
    return 0;
}