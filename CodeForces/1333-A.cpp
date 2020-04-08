#include <bits/stdc++.h>

using namespace std;

int main() {
    char c[] = {'B', 'W'};
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        bool even = ((n % 2) == 0) or ((m % 2) == 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == (m - 1)) {
                    if (n % 2 == 0 and m % 2 == 0) {
                        cout << 'B';
                    } else
                        cout << c[(i + j) & 1];

                } else if (even and (i == (n - 1) and j == (m - 1)))
                    cout << 'B';
                else
                    cout << c[(i + j) & 1];
            }
            cout << endl;
        }
    }
    return 0;
}