#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    cout << 2;
    for (int i = 1; i < n; i++)
        cout << 3;
    cout << endl;
}

int main() {
    int t;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}