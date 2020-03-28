#include <bits/stdc++.h>

#define SIZE 3000
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

vector<pii> getPrimeFactorization(int n) {
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

    return prime_powers;
}

int main() {
    bitSieve(SIZE);

    int n;
    cin >> n;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        vector<pii> factorization = getPrimeFactorization(i);
        if (factorization.size() == 2) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}