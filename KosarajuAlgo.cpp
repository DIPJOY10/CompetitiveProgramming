#include <bits/stdc++.h>
using namespace std;

//we use the Kosaraju's algo to find all the strongly connected components in a directed graph.
//a strongly connected component(SCC) is a component of a directed graph in which we can go from every node to every other.

// we use three steps:
//1. find the topological sort of the directed graph,i.e. the nodes in the order of their finishing time.
//2.Transpose the given graph.
//3.Do DFS according the the topo sort

//Time Complexity: O(N+E)

//DFS for topo sort
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &stk)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, stk);
        }
    }
    stk.push(node);
}

//DFS on the transposed graph to print the SCCs.
void revDfs(int node, vector<int> transpose[], vector<int> &vis)
{
    vis[node] = 1;
    cout << node << " ";
    for (auto it : transpose[node])
    {
        if (!vis[it])
        {
            revDfs(it, transpose, vis);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    //considering 1-based indexing of nodes.
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //we consider the graph is directed and unweighted.
        adj[u].push_back(v);
    }

    //step 1:find the topo sort of the given graph.
    stack<int> stk;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, stk);
        }
    }

    //step 2:transpose the directed graph.
    vector<int> transpose[n + 1];

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    //step 3: apply DFS to find the SCCs
    while (!stk.empty())
    {
        int node = stk.top();
        stk.pop();
        if (!vis[node])
        {
            revDfs(node, transpose, vis);
            cout << endl;
        }
    }

    return 0;
}
