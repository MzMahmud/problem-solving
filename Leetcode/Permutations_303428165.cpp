class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all;
        permute(nums,0,all);
        return all;
    }
    
    void permute(vector<int> a, int start_index, vector<vector<int>> &all) {
        if (start_index == a.size())
            all.push_back(a);
        
        for (int i = start_index; i < a.size(); i++) {
            swap(a[start_index], a[i]);
            permute(a, start_index + 1,all);
        }
    }
};
