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

    void shortestPath(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V + 1];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

void Graph::shortestPath(int src, int end)
{

    priority_queue<iPair, vector<iPair>, greater<iPair>>
        pq;

    vector<int> dist(V + 1, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();

        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {

            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << dist[end] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Graph g(n);
    int u, v, w, s, d;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cin >> s >> d;
    g.shortestPath(s, d);

    return 0;
}