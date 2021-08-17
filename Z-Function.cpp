// Z function optimized implementation

//Z[i] denotes the longest common prefix in string s that is equal to the substring starting at i(i.e, the suffix of s starting at i)
//Time Complexity: O(n)

vector<int> z_func(string s)
{
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (r < i + z[i] - 1)
        {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

int main()
{
    string s;
    cin >> s;
    vector<int> z1 = z_func_trivial(s);
    vector<int> z2 = z_func(s);

    //pattern matching implementation in o(|s|+|t|)
    string pat;
    cin >> pat;
    string t = pat + "#" + s;
    vector<int> z = z_func(t);
    for (int i = 0; i < s.size(); i++)
    {
        if (z[i + pat.size() + 1] == pat.size())
        {
            cout << i << "-" << i + pat.size() - 1 << endl;
        }
    }
    return 0;
}
