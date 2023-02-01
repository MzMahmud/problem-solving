class Solution {
    public boolean isThree(int n) {
        int divisiors = 0;
        for (int d = 1; d * d <= n; ++d) {
            if (n % d == 0) {
                ++divisiors;
                int otherD = n / d;
                if (otherD != d) {
                    ++divisiors;
                }
                if (divisiors > 3) {
                    return false;
                }
            }
        }
        return divisiors == 3;
    }
}