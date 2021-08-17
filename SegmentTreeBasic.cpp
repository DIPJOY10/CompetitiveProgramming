//Range Query DS:SegTree Basic Implementation
//o(logn) for updates and queries and o(n) for build

struct Segtree
{
    int n;
    vector<int> tree;

    Segtree(int n1, vector<int> &arr)
    {
        n = n1;
        tree.resize(2 * n);
        for (int i = 0; i < n; i++)
        {
            tree[n + i] = arr[i];
        }
        for (int i = n - 1; i > 0; i--)
        {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];//can change as per operation
        }
    }

    void update(int node, int start, int end, int pos, int val)
    {
        //point update
        if (start == end)
        {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= pos)
            update(2 * node, start, mid, pos, val);
        else
            update(2 * node + 1, mid + 1, end, pos, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];//can change as per operation
    }

    int query(int node, int start, int end, int l, int r)
    {
        //range sum query
        //fully overlapping
        if (start >= l && end <= r)
        {
            return tree[node];
        }
        //disjoint
        if (l > end || r < start)
            return 0; //can change as per operation(identity element)

        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) +
               query(2 * node + 1, mid + 1, end, l, r);//can change as per operation
    }
};
