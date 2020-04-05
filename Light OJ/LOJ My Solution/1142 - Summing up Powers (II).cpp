/*
    LOJ 1142 - Summing up Powers (II)
    Author : Moaz Mahmud
    Date   : 05 Apr,2020

    Solution:
        Let,S(k)   = A + A^2 + A^3 + .... + A^k
        So, S(k-1) = A + A^2 + A^3 + .... + A^(k-1)
        Notice,
        S(k) = A*S(k-1) + A, S(0) = zero matrix
        Now this can be formulated in Matrix form,

        | S(k) |   |A    A|  | S(k-1) |   |A    A|k  | S(0) |
        |      | = |      |  |        | = |      |   |      |
        |  I   |   |0    I|  |   I    |   |0    I|   |   I  |

        So,now matrix exponentiation can be done in O(lg k)
        in each step a fix n^3 is needed to multiply matrices
        So,final comolexity O(n^3 lg k)

    END :D:D
*/
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;

matrix operator*(const matrix &a, const matrix &b) {
    // multiplies two n*n matrices
    int n = a.size();
    matrix res = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int k = 0; k < n; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
    return res;
}

matrix operator+(const matrix &a, const matrix &b) {
    // adds two n*n matrices
    int n = a.size();
    matrix res = a;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res[i][j] += b[i][j];
    return res;
}

ostream &operator<<(ostream &os, const matrix &a) {
    // prints an n*n matrix
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            os << a[i][j];
        os << endl;
    }
    return os;
}

matrix zeros(int n) { return matrix(n, vector<int>(n, 0)); }

matrix identity(int n) {
    matrix I(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        I[i][i] = 1;
    return I;
}

struct matrix22 {
    matrix a[2][2];

    matrix22() {}
    matrix22(const matrix22 &other) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                a[i][j] = other.a[i][j];
    }
    matrix22(matrix _a, matrix b, matrix c, matrix d) {
        a[0][0] = _a;
        a[0][1] = b;
        a[1][0] = c;
        a[1][1] = d;
    }
    matrix22 &operator=(const matrix22 &other) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                a[i][j] = other.a[i][j];
        return *this;
    }
};

matrix22 operator*(const matrix22 &a, const matrix22 &b) {
    int len = a.a[0][0].size();
    matrix Z = zeros(len);
    matrix22 res(Z, Z, Z, Z);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                res.a[i][j] = res.a[i][j] + a.a[i][k] * b.a[k][j];
    return res;
}

matrix operator%(const matrix &mat, int m) {
    matrix ret = mat;
    for (auto &row : ret)
        for (auto &val : row)
            val %= m;
    return ret;
}

matrix22 operator%(const matrix22 &mat, int m) {
    matrix22 ret;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            ret.a[i][j] = mat.a[i][j] % m;
    return ret;
}

matrix22 power(matrix22 a, int n, int mod) {
    if (n == 0) {
        int len = a.a[0][0].size();
        matrix Z = zeros(len);
        matrix I = identity(len);
        return matrix22(I, Z, Z, I);
    }
    matrix22 x = power(a, n / 2, mod);
    x = (x * x) % mod;
    if (n & 1)
        x = (x * a) % mod;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, cn = 1;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        matrix a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        matrix I = identity(n);
        matrix Z = zeros(n);

        matrix22 mat(a, a, Z, I);
        mat = power(mat, k, 10);
        cout << "Case " << (cn++) << ":\n";
        cout << mat.a[0][1];
    }
    return 0;
}
