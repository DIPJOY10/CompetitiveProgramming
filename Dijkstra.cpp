#include <bits/stdc++.h>
using namespace std;

//we use Dijkstra's Algorithm to find minimum distances from a source to all nodes
//in a Undirected Weighted Graph.

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        //we consider the graph is undirected and weighted.
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int source;
    cin >> source;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            if (dist[it.first] > dist[node] + it.second)
            {
                dist[it.first] = dist[node] + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}
