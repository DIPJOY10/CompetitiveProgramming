//reference problem:https://codeforces.com/contest/1625/problem/D

struct node
{
    node *child[2];
    int cnt;
    node()
    {
        child[0] = NULL;
        child[1] = NULL;
        cnt = 0;
    }
};

struct TRIE
{
    node *root;
    TRIE()
    {
        root = new node();
    }

    void insert(int num)
    {
        node *temp = root;
        for (int bit = 30; bit >= 0; bit--)
        {
            int curr = ((1 << bit) & num) > 0;
            if (!temp->child[curr])
            {
                temp->child[curr] = new node();
            }
            temp = temp->child[curr];
            temp->cnt++;
        }
    }

    int max_xor(int num)
    {
        node *temp = root;
        int ans = 0;
        for (int bit = 30; bit >= 0; bit--)
        {
            int curr = ((1 << bit) & num) > 0;
            if (curr == 1)
            {
                if (temp->child[0])
                {
                    ans += (1 << bit);
                    temp = temp->child[0];
                }
                else
                {
                    temp = temp->child[1];
                }
            }
            else
            {
                if (temp->child[1])
                {
                    ans += (1 << bit);
                    temp = temp->child[1];
                }
                else
                {
                    temp = temp->child[0];
                }
            }
        }
        return ans;
    }
};
