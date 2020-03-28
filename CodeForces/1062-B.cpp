#include <bits/stdc++.h>

#define SIZE 1000003
#define getBit(n, pos) ((bool)(n & (1 << pos)))
#define setBit(n, pos) (n = n | (1 << pos))

using namespace std;

typedef pair<int, int> pii;

int state[(SIZE / 64) + 2];
vector<int> nPrime;
void bitSieve(int n) {
    nPrime.push_back(2);

    int pos, limit = sqrt(n * 1.0) + 2;
    for (int i = 3; i <= n; i += 2) {
        pos = (i + 1) / 2;
        if (!getBit(state[pos >> 5], (pos & 31))) {
            nPrime.push_back(i);
            if (i < limit) {
                for (int j = i * i; j <= n; j += (2 * i)) {
                    pos = (j + 1) / 2;
                    setBit(state[pos >> 5], (pos & 31));
                }
            }
        }
    }
}

int power(int a, int b) {
    if (!b)
        return 1;
    int x = power(a, b / 2);
    x *= x;
    if (b & 1)
        x *= a;
    return x;
}

int main() {
    bitSieve(1000000);

    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << " " << 0 << endl;
        return 0;
    }

    vector<pii> prime_powers;
    for (int i = 0; i < nPrime.size() && nPrime[i] * nPrime[i] <= n; i++) {
        int power = 0;
        while (!(n % nPrime[i])) {
            n /= nPrime[i];
            power++;
        }
        if (power) {
            prime_powers.push_back(make_pair(nPrime[i], power));
        }
    }

    if (n != 1)
        prime_powers.push_back(make_pair(n, 1));

    int max_pow = -1;
    for (int i = 0; i < prime_powers.size(); i++)
        max_pow = max(max_pow, prime_powers[i].second);

    int p = -1;
    while (power(2, ++p) < max_pow)
        ;

    int nearest_power_of_2 = power(2, p);
    bool mul               = false;
    for (int i = 0; i < prime_powers.size(); i++) {
        if (nearest_power_of_2 != prime_powers[i].second) {
            mul = true;
            break;
        }
    }

    int steps = (p + (int)mul);

    int min_val = 1;
    for (int i = 0; i < prime_powers.size(); i++)
        min_val *= prime_powers[i].first;

    cout << min_val << " " << steps << endl;

    return 0;
}