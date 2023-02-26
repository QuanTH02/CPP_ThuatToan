#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[10001];
typedef pair<int, int> iPair;
iPair Q[200001];

typedef struct
{
    int index;
    int duration;
    vector<int> wait_work;
} Work;
Work work[10001];

bool cmp(int a, int b)
{
    vector<int>::iterator it;
    it = find(work[b].wait_work.begin(), work[b].wait_work.end(), a);
    if (it != work[b].wait_work.end())
        return true;
    else if (work[a].duration < work[b].duration)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a[10001];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        // cin >> d[i];
        cin >> work[i].duration;
        work[i].index = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> Q->first >> Q->second;
        work[Q->second].wait_work.push_back(Q->first);
    }
    sort(work + 1, work + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << work[i].index << " ";
    }
}