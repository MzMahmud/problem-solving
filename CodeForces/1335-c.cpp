#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);

    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        count[a]++;
    }
    int max_cout = -1;
    for (auto p : count) {
        max_cout = max(max_cout, p.second);
    }

    int ans = min(n >> 1, max_cout);
    while (ans > 0) {
        int avail = count.size();
        if (ans == max_cout)
            avail--;
        if (avail >= ans) {
            cout << ans << endl;
            return;
        }
        ans--;
    }
    cout << ans << endl;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}