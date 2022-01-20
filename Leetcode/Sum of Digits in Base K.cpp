class Solution {
public:
    int sumBase(int n, int k) {
        int sum_of_digits = 0;
        while(n) {
            sum_of_digits += n % k;
            n /= k;
        }
        return sum_of_digits;
    }
};
