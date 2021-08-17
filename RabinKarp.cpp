//Rabin-Karp Algorithm for String Matching

//Enumerate all occurrences of a pattern t in a string s in O(|s| +|t|) time
//Thus, we need to compute hash values of all |t| length substrings in s in O(1) time to do the task in linear time

// here we just check if hash(s[i...j])=has[pattern]
//thus, we can do this--> (hash(s[0...j])-hash(s[0...i-1]))%mod==(p^i*hash(pattern))%mod instead of finding the inverse modulo which takes extra logn factor time in precompuation

#define maxn 100005
int dp[maxn], p_pow[maxn];
const int p = 31;
const int mod = 1e9 + 7;

void computeHash(string s)
{
    //o(n) precomputation
    int power = 1;
    int hash = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        hash = (hash + (s[i] - 'a' + 1) * power) % mod;
        dp[i] = hash;
        p_pow[i] = power;
        power = power * p;
        power %= mod;
    }
}

int32_t main()
{
    memset(dp, 0, sizeof dp);
    memset(p_pow, 0, sizeof p_pow);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    if (s.size() < t.size())
    {
        cout << -1 << endl;
        return 0;
    }
    //precomputation
    computeHash(s);

    int hashPattern = 0, m = t.size(), power = 1;
    for (int i = 0; i < m; i++)
    {
        hashPattern = (hashPattern + (t[i] - 'a' + 1) * power) % mod;
        power = power * p;
        power %= mod;
    }
    //use sliding window technique
    for (int i = 0; i <= n - m; i++)
    {
        int substringHash = dp[i + m - 1];
        if (i != 0)
            substringHash -= dp[i - 1];
        if (substringHash < 0)
            substringHash += mod;
        if (substringHash % mod == (p_pow[i] * hashPattern) % mod)
        {
            cout << i << endl;
        }
    }

    return 0;
}
