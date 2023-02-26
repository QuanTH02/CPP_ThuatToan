#include <bits/stdc++.h>
using namespace std;
int visited[1000];
int pre[1000];
int t = 0;
int cycle;
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
        if (t == 1)
            return;
        visited[s] = 1;
        list<int>::iterator it;
        for (it = adj[s].begin(); it != adj[s].end(); ++it)
        {
            int v = *it;
            if (visited[v] == 1)
            {
                cout << "Do thi co chu trinh";
                t = 1;
                return;
            }
            else if (visited[v] == 0)
                DFS(v);
        }
        visited[s] = 2;
    };

    void BFS(int s)
    {
        queue<int> Q;
        Q.push(s);
        visited[s] = 1;
        pre[s] = -1;
        while (!Q.empty())
        {
            int v = Q.front();
            Q.pop();
            list<int>::iterator it;
            for (it = adj[v].begin(); it != adj[v].end(); it++)
            {
                int k = *it;
                if (visited[k] == 0)
                {
                    visited[k] = 1;
                    pre[k] = v;
                    Q.push(k);
                }
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
    memset(pre, -1, sizeof(pre));
    cycle = 0;
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    for (int i = 0; i < 5; i++)
    {
        if (visited[i] == 0)
        {
            g.BFS(i);
        }
    }

    g.DFS(0);
    if (t == 0)
        cout << "Do thi khong co chu trinh";
}