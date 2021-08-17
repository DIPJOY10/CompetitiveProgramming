//Prefix Function and Knuth-Morris-Pratt(KMP) Algorithm for string matching o(n+m) time

//prefix function o(n) optimized solution
vector<int> prefix_function(string &s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    string s;
    cin >> s;
    vector<int> pi = prefix_function(s);

    //using kmp for string matching
    string t;
    cin >> t;
    string text = t + "#" + s;
    vector<int> pikmp = prefix_function(text);
    for (int i = 0; i < text.size(); i++)
    {
        if (pikmp[i] == t.size())
        {
            cout << i - 2 * t.size() << "-" << i - t.size() - 1 << endl;
        }
    }

    return 0;
}
