//DSU using union by rank and path compression
struct DSU
{
    int n;
    vector<int> rank, par;

    DSU(int n)
    {
        rank.resize(n + 1);
        par.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int findPar(int node)
    {
        return par[node] = (par[node] == node ? node : findPar(par[node]));
    }

    void Unite(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u == v)
            return;

        if (rank[u] == rank[v])
            rank[u]++;
        if (rank[u] > rank[v])
            par[v] = u;
        else
            par[u] = v;
    }
};
