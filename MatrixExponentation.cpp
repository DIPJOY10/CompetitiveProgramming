const int MOD = 1e9 + 7;
struct Matrix{
    vector<vector<int>> mat;
    int rows,cols;

    Matrix(vector<vector<int>> values): mat(values), rows(values.size()),
        cols(values[0].size()) {}

    static Matrix identity_matrix(int n)
    {
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &m) const 
    {
        int x = rows, y = m.cols;
        vector< vector<int> > result(rows, vector<int>(x, 0));
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++) {
                for(int k = 0; k < cols; k++) {
                    result[i][j] = (result[i][j] + mat[i][k] * 1ll * m.mat[k][j]) % MOD;
                }
            }
        return Matrix(result);
    }

    inline bool is_square() const
    {
        return rows == cols;
    }
};

Matrix fast_exponentiation(Matrix m, int power)
{
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.rows);

    while(power) {
        if(power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    }

    return result;
}
