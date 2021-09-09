#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

using Matrix = vector<vector<long>>;

Matrix operator*(const Matrix &a, const Matrix &b) {
    int r    = a.size();
    int c    = b[0].size();
    int kMax = b.size();
    Matrix res(r, vector<long>(c, 0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < kMax; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

Matrix operator%(const Matrix &a, long m) {
    Matrix res(a);
    for (auto &row : res)
        for (auto &elem : row)
            elem %= m;
    return res;
}

Matrix exp(const Matrix &a, long n, long m) {
    if (n == 0)
        return {{1, 0}, {0, 1}};
    Matrix res = exp(a, n / 2, m);

    res = (res * res) % m;
    return n % 2 == 0 ? res : (res * (a % m)) % m;
}

long fib(long a, long b, long n, long m) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    Matrix A    = {{1, 1}, {1, 0}};
    Matrix F    = {{b}, {a}};
    Matrix nFib = exp(A, n - 1, m) * F;
    return nFib[0][0] % m;
}

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

const long MOD = 1e9 + 7;

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n             = stoi(ltrim(rtrim(n_temp)));
    long gcdOfIndices = 0;

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string a_temp;
        getline(cin, a_temp);

        long a       = stol(ltrim(rtrim(a_temp)));
        gcdOfIndices = gcd(a, gcdOfIndices);
    }
    fout << fib(0, 1, gcdOfIndices, MOD) << "\n";
    fout.close();
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end());

    return s;
}
