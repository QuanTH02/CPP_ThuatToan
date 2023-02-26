#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string replaceStr(string s1, string s2, string s3)
{
    int index;
    while ((index = s3.find(s1)) != string::npos)
    {
        s3.replace(index, s1.length(), s2);
    }
    return s3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str1, str2, T;
    getline(cin, str1);
    getline(cin, str2);
    getline(cin, T);
    string ans = replaceStr(str1, str2, T);
    cout << ans;
    return 0;
}