#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;

bool cmp(int a, int b) { return a > b; }

void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;

    sort(begin(a), end(a), cmp);

    int ans = 0;
    ld sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if ((sum / (i + 1.0)) >= x)
            ans++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
