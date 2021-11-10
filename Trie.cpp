//basic trie D.S

const int alphabet = 26;

class Trie
{
public:
    class Node
    {
    public:
        int cnt;
        Node *child[alphabet];
        Node()
        {
            cnt = 0;
            for (int i = 0; i < alphabet; i++)
                child[i] = NULL;
        }
    };

    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        int sz = (int)word.size();
        int idx = 0;
        Node *it = root;
        while (idx < sz)
        {
            int c = word[idx] - 'a';
            if (!it->child[c])
            {
                it->child[c] = new Node();
            }
            it = it->child[c];
            idx++;
        }
        it->cnt++;
    }

    bool search(string word)
    {
        int sz = (int)word.size();
        int idx = 0;
        Node *it = root;
        while (idx < sz)
        {
            int c = word[idx] - 'a';
            if (!it->child[c])
            {
                return false;
            }
            it = it->child[c];
            idx++;
        }
        return it->cnt;
    }

    void del(string word)
    {
        int sz = (int)word.size();
        int idx = 0;
        Node *it = root;
        while (idx < sz)
        {
            int c = word[idx] - 'a';
            if (!it->child[c])
            {
                return;
            }
            it = it->child[c];
            idx++;
        }
        if (it->cnt)
            it->cnt--;
    }
};
