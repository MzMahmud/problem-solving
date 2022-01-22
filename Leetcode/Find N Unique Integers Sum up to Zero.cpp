class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> sum_to_zero(n, 0);
        int k = 0;
        for(int i = 1;(2 * i) <= n; ++i) {
            sum_to_zero[k++] = i;
            sum_to_zero[k++] = -i;
        }
        return sum_to_zero;
    }
};
