class Solution {
    int digit_sum(int n){
        int sum = 0;
        while(n){
            int d = (n % 10);
            sum += d*d;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        while(!(n == 1 || n == 89))
            n = digit_sum(n);
        return n == 1;
    }
};