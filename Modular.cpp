const int MOD = 1000000007;
struct Mint
{
    int val;

    Mint(long long v = 0)
    {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }

    Mint power(long long p) const
    {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0)
        {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }
        return result;
    }

    Mint mod_inv(int a, int m = MOD) const
    {
        Mint res(1), x(a);
        int y = m - 2;
        while (y)
        {
            if (y & 1)
            {
                res *= x;
            }
            y >>= 1;
            x *= x;
        }
        return res;
    }
    Mint inv() const
    {
        return mod_inv(val);
    }

    Mint &operator+=(const Mint &other)
    {
        val += other.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    Mint &operator-=(const Mint &other)
    {
        val -= other.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    Mint &operator*=(const Mint &other)
    {
        val = (val * other.val) % MOD;
        return *this;
    }
    Mint &operator/=(const Mint &other)
    {
        return *this *= other.inv();
    }

    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }

    Mint &operator++()
    {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint &operator--()
    {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }

    friend ostream &operator<<(ostream &stream, const Mint &m)
    {
        return stream << m.val;
    }
    friend istream &operator>>(istream &stream, Mint &m)
    {
        return stream >> m.val;
    }
};
