#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a, max_a, b;
    cin >> b;
    max_a = a = b;
    cout << a << " ";
    for (int i = 1; i < n; i++) {
        cin >> b;

        a = b + max_a;
        cout << a << (i == (n - 1) ? '\n' : ' ');

        max_a = max(max_a, a);
    }
    return 0;
}