class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1.0 + 8.0*n) - 1.0)/2.0;
    }
};
