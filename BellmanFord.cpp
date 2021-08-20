#include <bits/stdc++.h>
using namespace std;

//Bellman Ford Algorithm to detect a negative cycle and to print the shortest path
//from a source to all other nodes.

//Time Complexity:O(N*E)

struct edge
{
    int u;
    int v;
    int wt;
    edge(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    // we consider 1-based indexing of the nodes.
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        //we consider the graph is directed and weighted.
        edges.push_back(edge(u, v, wt));
    }

    int source;
    cin >> source;

    vector<int> dist(n + 1, INT_MAX);
    dist[source] = 0;

    //N-1 cycles of the algo.
    for (int i = 1; i < n; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    //check for negative cycle
    int flag = 1;
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            flag = 0;
            cout << "Negative Cycle" << endl;
            return 0;
        }
    }

    if (flag)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " " << dist[i] << endl;
        }
    }

    return 0;
}
