class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> groups;
        vector<vector<int>> out;
        
        for(int i = 0;i < groupSizes.size();i++){
            if(groups[groupSizes[i]].size() == groupSizes[i]){
                out.push_back(groups[groupSizes[i]]);
                groups[groupSizes[i]].clear();
            }
            groups[groupSizes[i]].push_back(i);
        }
        
        for(auto g : groups){
            if(g.second.size() != 0)
                out.push_back(g.second);
        }
        
        return out;
    }
};