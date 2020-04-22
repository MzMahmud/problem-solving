#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        long long n;
        cin >> n;
        long long p = 4;
        while (true) {
            if (!(n % (p - 1))) {
                cout << n / (p - 1) << endl;
                break;
            }
            p <<= 1;
        }
    }
    return 0;
}