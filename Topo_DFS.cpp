#include <bits/stdc++.h>
using namespace std;
int visited[1000];
int pre[1000];
list<int> lst;
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

    void topoSort()
    {
        stack<int> Stack;
        for (int i = 0; i < numVertex(); i++)
        {
            if (visited[i] == 0)
                DFS_topo(i, Stack);
        }
        while (!Stack.empty())
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    };

    void DFS_topo(int s, stack<int> &Stack)
    {
        visited[s] = 1;
        list<int>::iterator it;
        for (it = adj[s].begin(); it != adj[s].end(); ++it)
        {
            int v = *it;
            if (visited[v] == 0)
            {
                DFS_topo(v, Stack);
            }
        }
        Stack.push(s);
    };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(visited, 0, sizeof(visited));
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.topoSort();
}