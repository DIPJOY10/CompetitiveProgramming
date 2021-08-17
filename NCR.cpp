//binomial coefficient using dp
    int ncr[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                ncr[i][j] = 1;
            else
                ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        }
    }
