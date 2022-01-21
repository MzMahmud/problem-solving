class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        // it works because
        // if gcd(a[0], ..., a[n-1]) = 1, there must exist a subset S, with gcd(S) = 1
        // and by Bazeout Lemma those element would produce a linear equation = 1
        int gcd = 0;
        for(const int &num : nums) {
            gcd = __gcd(gcd, num);
        }
        return gcd == 1;
    }
};
