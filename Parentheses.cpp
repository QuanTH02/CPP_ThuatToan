#include <bits/stdc++.h>
using namespace std;
vector<char> cvtr;

bool check(int a, int b)
{
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
        return true;
    else
        return false;
}

int Solution(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '[' || str[i] == '(' || str[i] == '{')
            cvtr.push_back(str[i]);
        else if (check(cvtr.back(), str[i]))
            cvtr.pop_back();
        else
            return 0;
    }
    if (cvtr.size() == 0)
        return 1;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    cout << Solution(str);
    return 0;
}