#include <bits/stdc++.h>
using namespace std;
int visited[100001];
int m, n;
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
    void BFS(int s)
    {

        queue<int> Q;
        vector<int> S;

        Q.push(s);
        visited[s] = 1;

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
                    Q.push(k);
                }
            }
        }
    };
    int check()
    {

        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                count++;
                BFS(i);
            }
        }

        return count;
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
    cout << g.check();
}