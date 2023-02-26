#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int arr[6] = {100, 60, 70, 65, 80, 111};
    stack<int> s;
    int span[6];
    span[0] = 0;
    s.push(0);
    cout << span[0] << " ";
    for (int i = 1; i < 6; i++)
    {
        while (!s.empty() && (arr[i] > arr[s.top()]))
        {
            s.pop();
        }
        if (s.empty())
            span[i] = i;
        else
            span[i] = i - s.top() - 1;
        s.push(i);
        cout << span[i] << " ";
    }
}