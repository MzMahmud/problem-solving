class Solution {
    // revert half of the number and compare
    // n   123321 12332 1233 123
    // rev 0      1     12   123
    // n   1234321 123432 12343  1234 123
    // rev 0       1      12     123  1234
    // so half is reaced when rev > n
    // when iteration is done, check rev == n for even, rev/10 == n or odd
    // special case n has 0 in the end always false except 0
    public boolean isPalindrome(int n) {
        if(n < 0 || (n != 0 && n % 10 == 0)) {
            return false;
        }
        int halfReverseN = 0;
        while(halfReverseN < n) {
            halfReverseN = halfReverseN * 10 + n % 10;
            n /= 10;
        }
        return halfReverseN == n || (halfReverseN/10) == n; 
    }
}
