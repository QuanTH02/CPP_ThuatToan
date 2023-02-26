#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int kq[100000];
int checkphone(string s)
{
    if (s.length() != 10)
        return 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return 0;
    }
    return 1;
}
int count_time(string a, string b)
{
    int start = 3600 * ((a[0] - '0') * 10 + a[1] - '0') + 60 * ((a[3] - '0') * 10 + a[4] - '0') + (a[6] - '0') * 10 + a[7] - '0';
    int end = 3600 * ((b[0] - '0') * 10 + b[1] - '0') + 60 * ((b[3] - '0') * 10 + b[4] - '0') + (b[6] - '0') * 10 + b[7] - '0';
    return end - start;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<string, int> numbercalls, time_call;
    string call, from_number, to_number, date, from_time, to_time, statement, sdt;
    int incorrect_num = 0;
    int i = 0, a = 0, k = 0;
    while (true)
    {
        cin >> call;
        if (call == "#")
            break;
        cin >> from_number >> to_number >> date >> from_time >> to_time;
        if (checkphone(from_number) == 0 || checkphone(to_number) == 0)
            incorrect_num++;
        numbercalls[from_number]++;
        time_call[from_number] += count_time(from_time, to_time);
        i++;
    }
    while (true)
    {
        cin >> statement;
        if (statement == "#")
            break;
        else if (statement == "?check_phone_number")
        {
            if (incorrect_num == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (statement == "?number_calls_from")
        {
            cin >> sdt;
            cout << numbercalls[sdt] << "\n";
        }
        else if (statement == "?number_total_calls")
            cout << i << "\n";
        else if (statement == "?count_time_calls_from")
        {
            cin >> sdt;
            cout << time_call[sdt] << "\n";
        }
    }
    return 0;
}
