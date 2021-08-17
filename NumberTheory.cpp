//number theory fundamental functions
//inspired by galen_colin
//add "using namespace number_theory;" to use it

namespace number_theory
{
    //primality test O(sqrt(n)/6)
    bool isprime(ll n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

    //sieve O(nloglogn)
    int N = 2e6 + 5;
    vector<int> primes(N, 1);
    void sieve()
    {
        for (int i = 2; i <= N; i++)
        {
            if (primes[i])
            {
                for (int j = i * i; j <= N; j += i)
                {
                    primes[j] = 0;
                }
            }
        }
    }

    //get all primes from 1 to n O(nloglogn)
    vector<int> primelist;
    void generatePrimes(int n)
    {
        sieve();
        for (int i = 2; i <= n; i++)
        {
            if (primes[i])
            {
                primelist.push_back(i);
            }
        }
    }

    //prime factorize O(sqrt(n))
    vector<int> factorize(int n)
    {
        vector<int> factors;
        while (n % 2 == 0)
        {
            factors.push_back(2);
            n /= 2;
        }
        for (int i = 3; i * i <= n; i += 2)
        {
            while (n % i == 0)
            {
                factors.push_back(i);
                n /= i;
            }
        }
        if (n > 1)
        {
            factors.push_back(n);
        }
        return factors;
    }

    //get all divisors O(sqrt(n))
    vector<int> getdivs(int n)
    {
        vector<int> divisors;
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                divisors.push_back(i);
                if (i != n / i)
                    divisors.push_back(n / i);
            }
        }

        return divisors;
    }
}
