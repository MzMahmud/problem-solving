class Solution {
public:
    int arrangeCoins(int n) {
        // k*(k+1) <= n < (k+1)(k+2)/2
        // k = floor((sqrt(1 + 8.0 * n) - 1)/2)
        return (sqrt(1 + 8.0 * n) - 1)/2;
    }
};
