class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> lower_divisor, higher_divisor;
        for(int d = 1; d * d <= n; ++d) {
            if(n % d == 0) {
                lower_divisor.push_back(d);
                int d_pair = n / d;
                if(d_pair != d) {
                    higher_divisor.push_back(d_pair);
                }
            }
        }
        int n_lower_divisor = lower_divisor.size();
        int n_higher_divisor = higher_divisor.size();
        int n_total_divisor = n_lower_divisor + n_higher_divisor;
        
        if(1 <= k && k <= n_lower_divisor) {
            return lower_divisor[k - 1];
        } else if (k <= n_total_divisor){
            k -= n_lower_divisor;
            return higher_divisor[higher_divisor.size() - k];
        }
        return -1;
    }
};
