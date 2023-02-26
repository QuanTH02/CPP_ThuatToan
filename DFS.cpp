#include <bits/stdc++.h>
using namespace std;
int visited[1000];
int pre[1000];
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
                pre[v] = s;
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
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(4, 0);
    g.DFS(1);
}