#include <bits/stdc++.h>
using namespace std;
int visited[1000];
int indegree[1000];
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

    void topoSort_xoadandinh()
    {
        vector<int> in_degree(V, 0);
        for (int i = 0; i < V; i++)
        {
            list<int>::iterator it;
            for (it = adj[i].begin(); it != adj[i].end(); ++it)
            {
                in_degree[*it]++;
            }
        }
        queue<int> Q;
        for (int v = 0; v < V; v++)
        {
            if (in_degree[v] == 0)
                Q.push(v);
        }
        vector<int> topo_order;
        int num = 0;
        while (!Q.empty())
        {
            int v = Q.front();
            Q.pop();
            num++;
            topo_order.push_back(v);
            list<int>::iterator it;
            for (it = adj[v].begin(); it != adj[v].end(); ++it)
            {
                int k = *it;
                in_degree[k]--;
                if (in_degree[k] == 0)
                {
                    Q.push(k);
                }
            }
        }
        if (num != V)
            cout << "Do thi khong co TOPO";
        else
        {
            for (int i = 0; i < V; i++)
            {
                cout << topo_order[i] << " ";
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
    memset(indegree, 0, sizeof(indegree));
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.topoSort_xoadandinh();
}