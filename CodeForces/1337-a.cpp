#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << b << " " << c << " ";
    int z = c;
    while ((b + c) <= z && z <= d)
        z++;
    cout << z << endl;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}