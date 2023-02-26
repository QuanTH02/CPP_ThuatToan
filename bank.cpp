#include <iostream>
#include <cstring>
#include <map>
#include <list>
using namespace std;
map<string, int> money_trans;
list<string> acc;
int total_money = 0, count = 0;
typedef struct
{
    string from;
    string to;
} Trans;
Trans trans[10000000];

int check(string str, int k, int i, int n)
{
    string str1;
    int ans = 0, k1, i1;
    if (count == 0)
    {
        str1 = str;
        k1 = k;
    }
    if (k == 0)
    {
        if (str == str1)
            return 1;
        else
        {
            count = 0;
            ans = check(str1, k1, i1, n);
        }
    }
    while (i < n)
    {
        if (trans[i].from == str)
        {
            count++;
            if (count == 1)
                i1 = i;
            ans = check(trans[i].to, k - 1, 0, n);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string f_acc, t_acc, time, atm, statement;
    int money;
    int i = 0, k;
    while (true)
    {
        cin >> f_acc;
        if (f_acc == "#")
            break;
        cin >> t_acc >> money >> time >> atm;
        money_trans[f_acc] += money;
        total_money += money;
        acc.push_back(f_acc);
        acc.push_back(t_acc);
        trans[i].from = f_acc;
        trans[i].to = t_acc;
        i++;
    }
    while (true)
    {
        cin >> statement;
        if (statement == "#")
        {
            break;
        }
        else if (statement == "?number_transactions")
        {
            cout << i << endl;
        }
        else if (statement == "?total_money_transaction")
        {
            cout << total_money << endl;
        }
        else if (statement == "?list_sorted_accounts")
        {

            acc.sort();
            acc.unique();
            list<string>::iterator it;
            for (it = acc.begin(); it != acc.end(); ++it)
            {
                cout << *it << " ";
            }
            cout << endl;
        }

        else if (statement == "?total_money_transaction_from")
        {
            cin >> f_acc;
            cout << money_trans[f_acc] << endl;
        }
        else if (statement == "?inspect_cycle")
        {
            cin >> f_acc >> k;
            cout << check(f_acc, k, 0, i);
        }
    }
    return 0;
}
