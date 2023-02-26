#include <bits/stdc++.h>
using namespace std;
int visited[1000];
int pre[1000];
int disc[1000] = {0};
int low[1000];
bool isAP[1000] = {false};
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
        adj = new list<int>[V];
    };
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        // adj[w].push_back(v);
    };
    void APUtil(int u, int &time, int parent)
    {
        int children = 0;
        visited[u] = 1;
        disc[u] = low[u] = ++time;

        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                children++;
                APUtil(v, time, u);

                low[u] = min(low[u], low[v]);
                if (parent != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            }
            else if (v != parent)
                low[u] = min(low[u], disc[v]);
        }
        if (parent == -1 && children > 1)
            isAP[u] = true;
    };

    void AP()
    {
        int time = 0, par = -1;
        for (int u = 0; u < V; u++)
            if (!visited[u])
                APUtil(u, time, par);
        for (int u = 0; u < V; u++)
            if (isAP[u] == true)
                cout << u << " ";
    };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(visited, 0, sizeof(visited));
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.AP();
}