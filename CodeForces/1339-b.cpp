#include <bits/stdc++.h>

using namespace std;

// void solve() {}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &ai : a)
            cin >> ai;

        sort(begin(a), end(a));

        list<int> out;
        int i = 0, j = n - 1;
        while (i <= j) {
            if (i != j)
                out.push_front(a[j]);
            out.push_front(a[i]);
            i++, j--;
        }
        i = 0;
        for (int num : out) {
            cout << num << (i == (n - 1) ? '\n' : ' ');
            i++;
        }
    }
    return 0;
}