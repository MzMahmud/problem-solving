class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all;
        permutation(nums,0,all);
        return all;
    }
    
    void permutation(const vector<int>& a, int index, vector<vector<int>> &all) {
        if (index == a.size())
            all.push_back(a);

        for (int i = index; i < a.size(); i++) {
            vector<int> newA(a);
            swap(newA[index], newA[i]);
            permutation(newA, index + 1, all);
        }
    }
};
