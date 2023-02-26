#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    vector<int> pos;
    vector<int> peak;
} PeakData;

PeakData pick_peaks(vector<int> v)
{
    PeakData result;
    int n = v.size();
    int index = 0, value;

    for (int i = 1; i < n - 1; i++)
    {
        if (v[i - 1] < v[i])
        {
            index = i - 1;
            value = v[i];
        }
        if (v[i] > v[i + 1] && v[i] > v[index])
        {
            result.pos.push_back(index + 1);
            result.peak.push_back(v[i]);
            index = i;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    PeakData data = pick_peaks({3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3});
    for (int i = 0; i < data.pos.size(); i++)
    {
        cout << data.pos[i] << " " << data.peak[i] << endl;
    }
}