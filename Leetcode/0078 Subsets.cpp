class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all;
        
        findSubset({},nums,0,all);
        
        return all;
    }
    
    void findSubset(vector<int> subset,const vector<int>& set,
                    int index         ,vector<vector<int>>& all ) {
        
        if (index == set.size()) {
            all.push_back(subset);
            return;
        }
        
        
        findSubset(subset, set, index + 1, all);
        
        subset.push_back(set[index]);
        findSubset(subset, set, index + 1, all);
    }
};
