#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        long long n;
        cin >> n;
        if (n % 4) {
            cout << "NO" << endl;
            continue;
        }
        n = n >> 1;
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
            cout << 2 * i << " ";

        for (int i = 1; i < n; i++)
            cout << (2 * i - 1) << " ";
        cout << (3 * n - 1) << endl;
    }
    return 0;
}