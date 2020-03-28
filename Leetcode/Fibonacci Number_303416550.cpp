struct Mat22 {
    int a[2][2];

    Mat22() {
        for (int i = 0; i < 2; i++)
            for (int j  = 0; j < 2; j++)
                a[i][j] = 0;
    }

    Mat22(int _a[2][2]) {
        for (int i = 0; i < 2; i++)
            for (int j  = 0; j < 2; j++)
                a[i][j] = _a[i][j];
    }

    Mat22(const Mat22 &other) {
        for (int i = 0; i < 2; i++)
            for (int j  = 0; j < 2; j++)
                a[i][j] = other.a[i][j];
    }

    Mat22 &operator=(const Mat22 &other) {
        for (int i = 0; i < 2; i++)
            for (int j  = 0; j < 2; j++)
                a[i][j] = other.a[i][j];
        return *this;
    }

    Mat22 operator*(const Mat22 other) {
        int res[2][2] = {};
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    res[i][j] += a[i][k] * other.a[k][j];
        return Mat22(res);
    }
};

void print(const Mat22 &a) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j)
            cout << a.a[i][j] << " ";
        cout << endl;
    }
}

Mat22 power(Mat22 a, int n) {
    if (!n) {
        int a[2][2] = {{1, 0}, {0, 1}};
        return Mat22(a);
    }
    Mat22 ans = power(a, n >> 1);
    ans       = ans * ans;
    if (n & 1)
        ans = ans * a;
    return ans;
}

class Solution {
  public:
    int fib(int N) {
        int a[2][2] = {{1, 1}, {1, 0}};
        Mat22 ans(a);
        ans = power(a, N + 1);
        return ans.a[1][1];
    }
};
