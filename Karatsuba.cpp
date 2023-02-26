#include <bits/stdc++.h>
using namespace std;

string add(string x, string y)
{
    int length = max(x.size(), y.size());
    int carry = 0;
    int sum_col;
    string result;

    while (x.size() < length)
        x.insert(0, "0");

    while (y.size() < length)
        y.insert(0, "0");
    for (int i = length - 1; i >= 0; i--)
    {
        sum_col = (x[i] - '0') + (y[i] - '0') + carry;
        carry = sum_col / 10;
        result.insert(0, to_string(sum_col % 10));
    }

    if (carry)
        result.insert(0, to_string(carry));

    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string subtract(string x, string y)
{
    int length = max(x.size(), y.size());
    int diff;
    string result;

    while (x.size() < length)
        x.insert(0, "0");

    while (y.size() < length)
        y.insert(0, "0");

    for (int i = length - 1; i >= 0; i--)
    {
        diff = (x[i] - '0') - (y[i] - '0');
        if (diff >= 0)
            result.insert(0, to_string(diff));
        else
        {
            int j = i - 1;
            while (j >= 0)
            {
                x[j] = ((x[j] - '0') - 1) % 10 + '0';
                if (x[j] != '9')
                    break;
                else
                    j--;
            }
            result.insert(0, to_string(diff + 10));
        }
    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string karatsuba(string x, string y)
{
    int length = max(x.size(), y.size());

    while (x.size() < length)
        x.insert(0, "0");

    while (y.size() < length)
        y.insert(0, "0");

    if (length == 1)
        return to_string((x[0] - '0') * (y[0] - '0'));

    string x0 = x.substr(0, length / 2);
    string x1 = x.substr(length / 2, length - length / 2);
    string y0 = y.substr(0, length / 2);
    string y1 = y.substr(length / 2, length - length / 2);

    string p0 = karatsuba(x0, y0);
    string p1 = karatsuba(x1, y1);
    string p2 = karatsuba(add(x0, x1), add(y0, y1));
    string p3 = subtract(p2, add(p0, p1));

    for (int i = 0; i < 2 * (length - length / 2); i++)
        p0.append("0");
    for (int i = 0; i < length - length / 2; i++)
        p3.append("0");

    string result = add(add(p0, p1), p3);

    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    cout << karatsuba(a, b);
    return 0;
}