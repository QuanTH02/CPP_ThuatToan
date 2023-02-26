#include <bits/stdc++.h>
using namespace std;
int visited[100001];
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
        adj[w].push_back(v);
    };
    void DFS(int s)
    {

        visited[s] = 1;
        cout << s << " ";

        list<int>::iterator it;
        for (it = adj[s].begin(); it != adj[s].end(); ++it)
        {
            int v = *it;
            if (visited[v] == 0)
            {
                visited[v] = 1;
                DFS(v);
            }
        }
    };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    int v, w;

    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        cin >> v >> w;
        g.addEdge(v, w);
    }
    g.DFS(1);
}