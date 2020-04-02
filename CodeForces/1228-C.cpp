#include <bits/stdc++.h>

#define SIZE 100000

#define getBit(n, pos) ((bool)(n & (1 << pos)))
#define setBit(n, pos) (n = n | (1 << pos))

typedef long long ll;

using namespace std;

int state[((SIZE + 10) / 64) + 2];
vector<ll> nPrime;
void bit_sieve(ll n) {
    nPrime.push_back(2);
    int pos;
    ll limit = sqrt(n * 1.0) + 2;
    for (ll i = 3; i <= n; i += 2) {
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

void insert_primes(ll n, vector<ll> &primes) {
    for (ll i = 0; i < nPrime.size() && nPrime[i] * nPrime[i] <= n;
         ++i) {

        if (!(n % nPrime[i])) {
            primes.push_back(nPrime[i]);

            while (!(n % nPrime[i]))
                n /= nPrime[i];
        }
    }
    if (n != 1)
        primes.push_back(n);
}

ll power_p_in_fact_n(ll p, ll n) {
    ll ans = 0;
    while (n / p != 0) {
        ans += (n / p);
        n /= p;
    }
    return ans;
}

const ll MOD = 1000000007L;

ll big_mod(ll a, ll b, ll M) {
    if (!b)
        return (1 % M);

    ll x = big_mod(a, b >> 1, M);

    x = ((x % M) * (x % M)) % M;
    if (b & 1)
        x = (x * (a % M)) % M;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bit_sieve(SIZE);

    ll n, x;
    vector<ll> primes;

    cin >> x >> n;

    insert_primes(x, primes);

    ll ans = 1;
    for (auto p : primes) {
        ll k = power_p_in_fact_n(p, n);
        ans  = (ans * big_mod(p, k, MOD)) % MOD;
    }

    cout << (ans % MOD) << endl;
    return 0;
}
