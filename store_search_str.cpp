#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
set<string> set_str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str, str2;
    while (true)
    {
        cin >> str;
        if (str == "*")
            break;
        set_str.insert(str);
    }
    set<string>::iterator it;
    while (true)
    {
        cin >> str;
        if (str == "***")
            break;
        else if (str == "find")
        {
            cin >> str2;

            it = set_str.find(str2);
            if (it == set_str.end())
                cout << '0' << endl;
            else
                cout << '1' << endl;
        }
        else if (str == "insert")
        {
            cin >> str2;
            if (it != set_str.end())
                cout << '0' << endl;
            else
            {
                set_str.insert(str2);
                cout << '1' << endl;
            }
        }
    }
}
