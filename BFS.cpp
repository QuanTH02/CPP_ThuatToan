#include <bits/stdc++.h>
using namespace std;
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
    void BFS(int s)
    {
        queue<int> Q;
        vector<int> S;
        int visited[1000];

        memset(visited, 0, sizeof(visited));
        Q.push(s);
        visited[s] = 1;

        while (!Q.empty())
        {
            int v = Q.front();
            S.push_back(v);
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
        for (int i = 0; i < S.size(); ++i)
        {
            cout << S[i];
            if (i != S.size() - 1)
                cout << "->";
        }
        cout << endl;
    };
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(4, 0);
    g.BFS(1);
}