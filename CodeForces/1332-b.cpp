#include <bits/stdc++.h>

using namespace std;

void solve(const vector<int> &primes) {
    int n;
    cin >> n;

    vector<int> ans;
    unordered_map<int, int> color;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int pi = 0; pi < primes.size(); pi++) {
            if (!(num % primes[pi])) {
                if (color.find(primes[pi]) == color.end()) {
                    color[primes[pi]] = color.size() + 1;
                }
                ans.push_back(primes[pi]);
                break;
            }
        }
    }

    cout << color.size() << endl;
    for (int i = 0; i < n; i++)
        cout << color[ans[i]] << (i == (n - 1) ? '\n' : ' ');
}

int main() {
    int t;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    cin >> t;
    while (t--) {
        solve(primes);
    }
    return 0;
}