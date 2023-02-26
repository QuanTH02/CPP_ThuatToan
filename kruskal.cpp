#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;
int n, m;
class Graph
{
    int V;

    list<pair<int, int>> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);

    void kruskal();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V + 1];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::kruskal()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Graph g(n);
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.kruskal();
    return 0;
}