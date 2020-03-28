class Solution {
public:
    int findNthDigit(int n) {
        long long ten_pow = 1;
        for(int i = 1;;i++){
            long long limit = i * 9 * ten_pow;
            if(n <= limit){
                --n;
                int num = ten_pow + (n / i);
                return to_string(num)[n % i] - '0';
            }
            n -= limit;
            ten_pow *= 10;
        }
    }
};
