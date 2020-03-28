#include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(int n) {
    double sqrtN = sqrt(n + .0);
    return ((int)sqrtN) == (sqrtN);
}

int main() {
    int n;
    cin >> n;

    for (int a = 1; a < n; a++) {
        int bb = n * n - a * a;
        if (isPerfectSquare(bb)) {
            cout << a << " " << (int)sqrt(bb + .0) << endl;
            return 0;
        }
    }

    for (int a = 1;; a++) {
        int mod_a = ((a % 4) * (a % 4)) % 4;
        int mod_n = ((n % 4) * (n % 4)) % 4;

        if ((mod_a + mod_n) == 3)
            continue;

        int cc = a * a + n * n;
        if (isPerfectSquare(cc)) {
            cout << a << " " << (int)sqrt(cc + .0) << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}