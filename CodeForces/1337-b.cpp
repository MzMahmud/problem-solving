#include <cstdio>
#include <cstring>

void solve() {
    int x, n, m;
    scanf("%d%d%d", &x, &n, &m);
    int low = 10 * m;
    while (x > low and n > 0) {
        x = (x >> 1) + 10;
        n--;
    }
    printf("%s\n", (x <= low) ? "YES" : "NO");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}