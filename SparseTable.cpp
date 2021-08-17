//Sparse Table: Range Query Data Structure
//O(1) for idempotent operations and O(logN) for normal queries

template <typename Node>
struct SparseTable
{
    vector<vector<Node>> table;
    vector<int> bin_log;
    int n;
    int maxLog;
    vector<int> a;
    SparseTable(int len, vector<int> &arr)
    {
        n = len;
        a = arr;
        table.resize(n);
        bin_log.resize(n + 1);
        maxLog = log2(n);
        bin_log[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            bin_log[i] = bin_log[i / 2] + 1;
        }
        for (int i = 0; i < n; i++)
        {
            table[i].resize(maxLog + 1);
            fill(table[i].begin(),table[i].end(), Node());
        }
        build();
    }
    void build()
    {
        for (int i = 0; i < n; i++)
        {
            table[i][0] = Node(a[i]);
        }
        for (int i = 1; i <= maxLog; i++)
        {
            for (int j = 0; (j + (1 << i)) <= n; j++)
            {
                table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
    Node query(int left, int right)
    {
        int j = bin_log[right - left + 1];
        Node ans = Node();
        ans.merge(table[left][j], table[right - (1 << j) + 1][j]);
        return ans;
    }
};
//change here according to the operation required
struct NodeType
{
    int val;
    NodeType()
    {
        val = 0;
    }
    NodeType(int v)
    {
        val = v;
    }
    void merge(NodeType &l, NodeType &r)
    {
        //change operation accordingly
        val = min(l.val, r.val);
    }
};
