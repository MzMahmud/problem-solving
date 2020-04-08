#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool yes = true, seen_1 = false, seen_minus_1 = false;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            if (!yes)
                continue;

            if (a[i] != b) {
                if (b < a[i] && !seen_minus_1)
                    yes = false;
                else if (b > a[i] && !seen_1)
                    yes = false;
            }

            seen_1 |= (a[i] == 1);
            seen_minus_1 |= (a[i] == -1);
        }
        cout << (yes ? "YES" : "NO") << endl;
    }
    return 0;
}