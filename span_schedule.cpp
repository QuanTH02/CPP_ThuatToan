#include <bits/stdc++.h>
using namespace std;

int indegree[10001];
int max1[10001];
int d[1000];
list<int> lst;
int n, m;
class Graph
{
    int V;
    list<int> *adj;

public:
    int numVertex()
    {
        return V;
    };
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V + 1];
    };
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        indegree[w]++;
    };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(indegree, 0, sizeof(indegree));
    memset(max1, -1, sizeof(max1));
    Graph g(n);
    int v, w;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v >> w;
        g.addEdge(v, w);
    }
    for (int i = 1; i <= n; i++)
    {
        if (max1[indegree[i]] < d[i])
            max1[indegree[i]] = d[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (max1[i] != -1)
            sum += max1[i];
    }
    cout << sum;
}