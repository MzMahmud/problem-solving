class Solution {
    static const int DIVISOR = 60;
    
    inline int get_remainder(const int &divident, const int &divisor) {
        return ((divident % divisor) + divisor) % divisor;
    }
public:
    int numPairsDivisibleBy60(vector<int>& times) {
        long pair_count = 0;
        unordered_map<int,int> remainder_occurrence;
        for(const int& time : times) {
            int remainder = get_remainder(time, DIVISOR);
            int required_remainder = get_remainder(DIVISOR - remainder, DIVISOR);
            pair_count += remainder_occurrence[required_remainder];
            ++remainder_occurrence[remainder];
        }
        return pair_count;
    }
};
