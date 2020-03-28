class Solution {
  public:
    int countPrimes(int n) {
        vector<bool> isPrime(n/2, 0);
        int limit = sqrt(n + 0.0) + 2;
        int nPrime = n > 2? 1 : 0;
        for (int i = 3; i < n; i += 2) {
            if (!isPrime[(i + 1) / 2]) {
                ++nPrime;
                if (i < limit)
                    for (int j = i * i; j <= n; j += (i * 2))
                        isPrime[(j + 1) / 2] = 1;
            }
        }
        return nPrime;
    }
};
