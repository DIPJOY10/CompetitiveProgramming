//binary lifting structure having both kth parent and lca functions
//O(nlogn) precomputation and o(logn) kth parent and lca 

struct BinaryLifting
{
    int n;
    int maxLog;
    vector<vector<int>> parent;
    vector<int> level;
    vector<int> bin_log;
    BinaryLifting(int n1, vector<int> adj[], int root)
    {
        n = n1;
        maxLog = log2(n) + 1;
        parent.resize(n + 1);
        level.resize(n + 1);
        fill(level.begin(), level.end(), 0);
        //assuming nodes numbered 1-n
        for (int i = 1; i <= n; i++)
        {
            parent[i].resize(maxLog + 1);
            for (int j = 0; j <= maxLog; j++)
            {
                parent[i][j] = -1;
            }
        }
        precompute(root, -1, adj);
        precomputeLogs();
    }

    void precompute(int node, int par, vector<int> adj[])
    {
        parent[node][0] = par;
        for (int i = 1; i <= maxLog; i++)
        {
            if (parent[node][i - 1] != -1)
            {
                parent[node][i] = parent[parent[node][i - 1]][i - 1];
            }
            else
            {
                parent[node][i] = -1;
            }
        }

        for (auto x : adj[node])
        {
            if (x != par)
            {
                level[x] = level[node] + 1;
                precompute(x, node, adj);
            }
        }
    }

    void precomputeLogs()
    {
        bin_log.resize(n + 1);
        bin_log[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            bin_log[i] = bin_log[i / 2] + 1;
        }
    }

    int kthParent(int node, int k)
    {
        int ans = node;
        while (k > 0)
        {
            int maxjump = bin_log[k];
            ans = parent[ans][maxjump];
            if (ans == -1)
                return -1;
            k -= (1 << maxjump);
        }

        return ans;
    }

    int lca(int u, int v)
    {
        if (level[u] < level[v])
        {
            swap(u, v);
        }
        u = kthParent(u, level[u] - level[v]);
        if (u == v)
        {
            return u;
        }

        for (int i = maxLog; i >= 0; i--)
        {
            if (parent[u][i] != parent[v][i])
            {
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        return parent[u][0];
    }
};
