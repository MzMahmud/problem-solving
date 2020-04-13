#include <bits/stdc++.h>

using namespace std;

int left_most_set_bit(int n) {
    for (int i = 31; i >= 0; i--)
        if (n & (1 << i))
            return i + 1;
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        cin >> a[0];
        int max_elem = a[0];
        int max_diff = 0;
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            if (a[i] >= max_elem)
                max_elem = a[i];
            else
                max_diff = max(max_diff, max_elem - a[i]);
        }
        if (max_diff == 0)
            cout << 0 << endl;
        else
            cout << left_most_set_bit(max_diff) << endl;
    }
    return 0;
}