//Range-Query DS: Segment Tree
//Generic Segtree, Inspired by HealthyUG
//supports range queries, point updates and range updates
//O(logN) for each operation

template <typename Node, typename Update>
struct Segtree
{
    int n;
    vector<Node> tree;

    Segtree(int n1, vector<int> &v)
    {
        n = n1;
        tree.resize(n << 2);
        fill(tree.begin(), tree.end(), Node());
        build(1, 0, n - 1, v);
    }

    void build(int node, int left, int right, vector<int> v)
    { 
        if (left == right)
        {
            tree[node] = Node(v[left]);
            return;
        }
        int mid = (left + right) >> 1;
        build(node << 1, left, mid, v);
        build(node << 1 | 1, mid + 1, right, v);
        tree[node].merge(tree[node << 1], tree[node << 1 | 1]);
    }

    Node query(int node, int left, int right, int query_left, int query_right)
    {
        if (left >= query_left && right <= query_right)
        {
            return tree[node];
        }
        if (left > query_right || right < query_left)
        {
            return Node();
        }

        int mid = (left + right) >> 1;
        Node ans, l, r;
        l = query(node << 1, left, mid, query_left, query_right);
        r = query(node << 1 | 1, mid + 1, right, query_left, query_right);
        ans.merge(l, r);
        return ans;
    }

    void pupd(int node, int left, int right, Update &upd)
    {
        if (left == right)
        {
            upd.apply(tree[node]);
            return;
        }
        int mid = (left + right) >> 1;
        if (mid >= upd.idx)
            pupd(node << 1, left, mid, upd);
        else
            pupd(node << 1 | 1, mid + 1, right, upd);
        tree[node].merge(tree[node << 1], tree[node << 1 | 1]);
    }

    void update(int index, int value)
    {
        Update upd = Update(index, value);
        pupd(1, 0, n - 1, upd);
    }

    int query(int l, int r)
    {
        Node ans = query(1, 0, n - 1, l, r);
        return ans.val;
    }
};

struct Node1
{
    int val;
    Node1()
    { //identity element
        val = 0;
    }

    Node1(int v)
    {
        val = v;
    }

    void merge(Node1 &u, Node1 &v)
    {
        val = u.val + v.val; //operation changes accordingly
    }
};

struct Update1
{
    int idx, v;
    Update1(int index, int value)
    {
        idx = index;
        v = value;
    }

    void apply(Node1 &u)
    {
        u.val = v;
    }
};
