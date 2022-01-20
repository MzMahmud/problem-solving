class Solution {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    int findGCD(vector<int>& nums) {
        int min_num = INT_MAX, max_num = -1;
        for(const int &num : nums) {
            min_num = min(min_num, num);
            max_num = max(max_num, num);
        }
        return gcd(min_num, max_num);
    }
};
