#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

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

const long MOD = 1e9 + 7;

int solve(int a, int b, int n) {
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    Matrix A    = {{1, 1}, {1, 0}};
    Matrix F    = {{b}, {a}};
    Matrix nFib = exp(A, n - 1, MOD) * F;
    return nFib[0][0] % MOD;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int a = stoi(first_multiple_input[0]);

        int b = stoi(first_multiple_input[1]);

        int n = stoi(first_multiple_input[2]);

        int result = solve(a, b, n);

        fout << result << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end   = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
