#include <bits/stdc++.h>
using namespace std;
int color[1000];

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
        adj[w].push_back(v);
    };
    bool isBipartite(int s)
    {
        queue<int> Q;
        Q.push(s);
        color[s] = 1;
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            list<int>::iterator it;
            for (it = adj[u].begin(); it != adj[u].end(); it++)
            {
                int v = *it;
                if (v == u)
                    return false;
                else if (color[v] == -1)
                {
                    color[v] = 1 - color[u];
                    Q.push(v);
                }
                else if (color[u] == color[v])
                    return false;
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (color[i] == 1)
            {
                cout << i << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < V; i++)
        {
            if (color[i] == 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
        return true;
    };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(color, -1, sizeof(color));
    Graph g(8);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(4, 3);
    g.addEdge(3, 1);
    g.addEdge(1, 5);
    g.addEdge(2, 6);
    g.addEdge(4, 0);
    g.addEdge(3, 7);
    g.addEdge(7, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 0);
    cout << g.isBipartite(1);
}