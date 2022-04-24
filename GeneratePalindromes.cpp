void getpals(string &num, vector<int> &pals)
{
    string t = num;
    reverse(t.begin(), t.end());
    string even = num + t;
    pals.push_back(stoll(even));
    for (int i = 0; i <= 9; i++)
    {
        char c = '0' + i;
        num.push_back(c);
        string odd = num + t;
        pals.push_back(stoll(odd));
        num.pop_back();
    }
}

void generate_palindromes(string &num, vector<int> &pals, int lim)
{
    int sz = num.size();
    if (sz > 0 && sz <= lim)
    {
        getpals(num, pals);
    }
    if (sz == lim)
    {
        return;
    }
    if (sz == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            char c = '0' + i;
            num.push_back(c);
            generate_palindromes(num, pals, lim);
            num.pop_back();
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            char c = '0' + i;
            num.push_back(c);
            generate_palindromes(num, pals, lim);
            num.pop_back();
        }
    }
}

// call this to get all palindromes with number of digits<required number of digits
vector<int> getPalindromes(int digits)
{
    vector<int> palindromes;
    // considering digits>=1 && digits<=11
    for (int i = 1; i <= 9; i++)
    {
        palindromes.push_back(i);
    }
    int halfDigits = (digits-1) / 2;
    string num = "";
    generate_palindromes(num, palindromes, halfDigits);
    return palindromes;
}
