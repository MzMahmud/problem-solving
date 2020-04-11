#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        bool valid = true;
        int prev_p = 0, prev_c = 0;
        for (int i = 0; i < n; i++) {
            int p, c;
            cin >> p >> c;

            if (c > p)
                valid = false;

            int del_p = p - prev_p;
            int del_c = c - prev_c;
            if (del_p < 0 || del_c < 0 || del_c > del_p)
                valid = false;

            prev_p = p;
            prev_c = c;
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}
