class Solution {
    // sliding window O(n) time, O(1) space
    public int tribonacci(int n) {
        if(n == 0) {
            return 0;
        }
        if(n < 3) {
            return 1;
        }
        int a = 0, b = 1, c = 1, d = 0;
        for(int k = 2;k < n; ++k) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
}