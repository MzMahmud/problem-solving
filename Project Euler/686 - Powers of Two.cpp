#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll leading_digit_2(ll j, ll d) {
    // returns d leading digits of 2^j
    // 10^k = 2^j
    // k = j*log(2)
    ld k              = j * log10l(2.0);
    ld k_frac         = k - (ll)k;
    ld leading_digits = powl(10.0, k_frac);
    ll d_digits       = leading_digits * powl(10, d - 1);
    return d_digits;
}

ll p(ll L, ll n) {
    ll j      = 0;
    ll count  = 0;
    ll digits = floorl(log10l(L)) + 1;
    while (++j) {
        if (L == leading_digit_2(j, digits)) {
            ++count;
            if (count == n)
                return j;
        }
    }
    return -1;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    cout << p(123, 678910) << endl;

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
    // answer in 193060223
    // python code in google colab took 1190.116s :3
    // C++ in may machine took 86.0535s :3 :3
}

// '''
// 2^i = 10^{frac + int}
//     = 10^frac * 10^int
//     = (the leading numbers) * 10^int
// '''
// import numpy as np

// def leading_digit_2(j, d):
//     """
//     returns d leading digits of 2^j
//     """
//     # 10^k = 2^j
//     # k = j*log(2)
//     k = j*np.log10(2.0)
//     k_frac = k - int(k)
//     leading_digits = np.power(10.0, k_frac)
//     d_digits = leading_digits*np.power(10, d-1)
//     return int(d_digits)

// def p(L, n):
//     j = 1
//     count = 0
//     digits = np.floor(np.log10(L)) + 1
//     while True:
//         if L == leading_digit_2(j, digits):
//             count += 1
//             if count == n:
//                 return j
//         j += 1

//     return None

// print(p(123, 678910))
// # answer in 193060223
// # but took a long time
// # google colab took 1190.116s :3
// # code have to be fixed!
