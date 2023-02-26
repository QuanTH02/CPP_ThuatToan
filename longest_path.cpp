#include <bits/stdc++.h>
using namespace std;
int dis[1000];

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

    pair<int, int> BFS_LP(int s)
    {
        pair<int, int> pr;
        int maxDis = 0, index;
        memset(dis, -1, sizeof(dis));
        queue<int> Q;
        Q.push(s);
        dis[s] = 0;

        while (!Q.empty())
        {
            s = Q.front();
            Q.pop();
            list<int>::iterator it;
            for (it = adj[s].begin(); it != adj[s].end(); it++)
            {
                int k = *it;
                if (dis[k] == -1)
                {
                    dis[k] = dis[s] + 1;
                    Q.push(k);
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (dis[i] > maxDis)
            {
                maxDis = dis[i];
                index = i;
            }
        }
        pr = make_pair(index, maxDis);
        return pr;
    };

    void longestPathLength()
    {
        pair<int, int> p1 = BFS_LP(0);
        pair<int, int> p2 = BFS_LP(p1.first);
        cout << "Duong di dai nhat trong do thi la tu dinh " << p1.first << " den dinh " << p2.first << ".Do dai: " << p2.second << endl;
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
    g.longestPathLength();
}