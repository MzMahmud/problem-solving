#include <bits/stdc++.h>

using namespace std;

inline bool between(int x, int y, int x1, int y1, int x2, int y2) {
    return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

void solve() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x[3], y[3];
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];

    if (!between(x[0], y[0], x[1], y[1], x[2], y[2])) {
        cout << "NO\n";
        return;
    }

    int dx = x[2] - x[1];
    int dy = y[2] - y[1];

    if (((a + b) > 0 and dx <= 0) or ((c + d) > 0 and dy <= 0)) {
        cout << "NO\n";
        return;
    }

    x[0] += (b - a);
    y[0] += (d - c);

    if (!between(x[0], y[0], x[1], y[1], x[2], y[2])) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
        return;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}