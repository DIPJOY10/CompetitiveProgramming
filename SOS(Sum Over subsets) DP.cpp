
/***************************Sum Over Subsets(SOS) Bitmask DP*******************************/

//we are given an array containing 2^n elements and we want to calculate a function f(x) where x is all possible masks for 2^n elements
//f(x)=(for all x)(sum over all a[i] where i is a submask of the mask x)

// Reference Blog - https://codeforces.com/blog/entry/45223

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[(1 << n)];
    for (int i = 0; i < (1 << n); i++)
        cin >> a[i];

    int f[(1 << n)]; //the function we need to return

    //brute force solution
    //T.C - O(4^n), S.C- O(2^n)
    memset(f, 0, sizeof f);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < (1 << n); i++)
        {
            if ((mask & i) == i) //checking if 'i' is a submask of 'mask'
            {
                f[mask] += a[i];
            }
        }
    }

    //better solution-we traverse only through the submasks of 'mask' and not through all masks
    //T.C - O(3^n), S.C- O(2^n)
    //proof of T.C --> https://cp-algorithms.com/algebra/all-submasks.html
    memset(f, 0, sizeof f);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        f[mask] += a[0];
        int t = mask;
        while (t)
        {
            f[mask] += a[t];
            t = (t - 1) & mask; //going through the submasks of 'mask' only
        }
    }

    //Optimal solution - Bitmask (SOS) dp
    //T.C - O(n*2^n), S.C - O(n*2^n)
    int dp[(1 << n)][n + 1], func[(1 << n)];
    memset(dp, 0, sizeof dp);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        dp[mask][0] = a[mask];
        for (int i = 1; i <= n; i++)
        {
            if (mask & (1 << (i - 1)))
            {
                dp[mask][i] = dp[mask][i - 1] + dp[mask ^ (1 << (i - 1))][i - 1];
            }
            else
            {
                dp[mask][i] = dp[mask][i - 1];
            }
            //note that the given ordering of loops explains the code well. but technically we can swap the order of the loops because for both the dimensions,
            //we need previously calculated dimensions. Thus, reversing the order of loops doesn't change anything in terms of final answer.
        }
        func[mask] = dp[mask][n];
    }

    //Most optimal solution (space optimization of the above dp)
    //T.C - O(n*2^n), S.C - O(2^n)
    int DP[(1 << n)];
    for (int i = 0; i < (1 << n); i++)
        DP[i] = a[i];
    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (mask & (1 << i))
            {
                DP[mask] += DP[mask ^ (1 << i)];
                //logic of space optimization

                //we already have the result for all submasks of 'mask' till i-1 bits
                //if the ith bit in 'mask' is not set, we do nothing.
                //if the ith bit in 'mask' is set, along with the existing answer, we add the answer when the ith bit is off.
                
                //note that unlike the previous 2d dp, here we cannot swap the order of the loops.
                //If we swap the order and do the same thing, it will give wrong results. This is because, for the ith bit,if the bit is set, 
                //we will add dp[mask^(1<<i)][n-1] instead of dp[mask^(1<<i)][i-1] to dp[mask], which is wrong.
            }
        }
    }

    return 0;
}
