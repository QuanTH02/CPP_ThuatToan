#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    int v;
    queue<int> st;
    while (true)
    {
        cin >> str;
        if (str == "#")
            break;
        else if (str == "PUSH")
        {
            cin >> v;
            st.push(v);
        }
        else if (str == "POP")
        {
            if (st.empty())
                cout << "NULL" << endl;
            else
            {
                v = st.front();
                cout << v << endl;
                st.pop();
            }
        }
    }
}