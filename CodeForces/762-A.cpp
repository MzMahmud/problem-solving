#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("in", "r", stdin);

    long long n, k;
    cin >> n >> k;

    vector<long long> divisors;
    for (long long i = 1; i * i <= n; i++) {
        if (!(n % i)) {
            divisors.push_back(i);
            long long j = n / i;
            if (i != j)
                divisors.push_back(j);
        }
    }
    sort(divisors.begin(), divisors.end());

    cout << (k > divisors.size() ? -1 : divisors[k - 1]) << endl;

    return 0;
}