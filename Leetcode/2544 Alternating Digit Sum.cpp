class Solution {
  public:
    int alternateDigitSum(int n) {
        int altSum = 0, sign = 1;
        for (char d : to_string(n)) {
            altSum += sign * (d - '0');
            sign *= -1;
        }
        return altSum;
    }
};