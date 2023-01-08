class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr),end(arr),
             [](int a,int b) -> bool{
                 int a_c = __builtin_popcount(a);
                 int b_c = __builtin_popcount(b);
                 return a_c == b_c ? a < b : a_c < b_c;
             });
        return arr;           
    }
};