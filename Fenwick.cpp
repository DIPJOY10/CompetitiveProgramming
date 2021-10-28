//Binary Indexed Tree/Fenwick Tree. O(log N) for point update and O(log N) for range sum query

class BIT
{
    //everything is 1-indexed
public:
    vector<int> fen;
    int sz;
    BIT(vector<int> arr, int n)
    {
        sz = n;
        fen.resize(n + 1);
        fill(fen.begin(), fen.end(), 0);
        build(arr);
    }

    void build(vector<int> arr)
    {
        for (int i = 1; i <= sz; i++)
        {
            int t = i;
            while (t <= sz)
            {
                fen[t] += arr[i - 1];
                t += (t & (-t));
            }
        }
    }

    void update(int idx, int val)
    {
        //point update-- add val to array[idx]
        while (idx <= sz)
        {
            fen[idx] += val;
            idx += (idx & (-idx));
        }
    }

    int query(int idx)
    {
        //returns the dynamic prefix sum till idx
        int sum = 0;
        while (idx >= 1)
        {
            sum += fen[idx];
            idx -= (idx & (-idx));
        }
        return sum;
    }

    int lowerbnd(int lim)
    {
        //returns the index till which prefix sum is <=lim
        int prevsum = 0, cur = 1;
        for (int i = log2(sz); i >= 0; i--)
        {
            if (fen[cur + (1 << i)] + prevsum <= lim)
            {
                cur = cur + (1 << i);
                prevsum += fen[cur];
            }
        }
        return cur;
    }
};
