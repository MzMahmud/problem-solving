class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n         = nums.size();
        long long sum = n & 1 ? ((n + 1) >> 1) * n : (n >> 1) * (n + 1);
        for (int num : nums)
            sum -= num;
        return sum;
    }
};
