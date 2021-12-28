
vector<int> fact(maxn, 1), invfact(maxn, 1);

int powm(int a, int b, int m)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

void prepare_factorials()
{
    invfact[0] = powm(1, mod - 2, mod);
    invfact[1] = invfact[0];
    for (int i = 2; i < maxn; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = powm(fact[i], mod - 2, mod);
    }
}
