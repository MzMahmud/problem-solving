#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; i++)
        printf("%c", ('a' + i % b));
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}