#include <bits/stdc++.h>
#define SIZE 1000000

using namespace std;

bool isPrime[(SIZE + 4) / 2];

void primeSieve(int n) {
    int limit = sqrt(n + 0.0) + 2;
    for (int i = 3; i <= n; i += 2) {
        if (!isPrime[(i + 1) / 2]) {
            if (i < limit) {
                for (int j = i * i; j <= n; j += (i * 2)) {
                    isPrime[(j + 1) / 2] = 1;
                }
            }
        }
    }
}

int main() {
    primeSieve(SIZE);

    int n;
    cin >> n;

    if (n == 1) {
        printf("1\n1\n");
        return 0;
    } else if (n == 2) {
        printf("1\n1 1\n");
        return 0;
    }

    n++; // 2 to n + 1
    cout << 2 << endl;
    cout << "1 "; // for 2

    for (int i = 3; i <= n; i++) {
        if (i & 1) { // odd
            cout << (isPrime[(i + 1) / 2] + 1);
        } else {
            cout << 2;
        }
        cout << (i == n ? '\n' : ' ');
    }

    return 0;
}