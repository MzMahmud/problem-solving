class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> seen;
        
        for(string s: strs){
            string str = s;
            sort(s.begin(),s.end());
            seen[s].push_back(str);
        }
        
        vector<vector<string>> out;
        for(auto s : seen)
            out.emplace_back(s.second);

        return out;
    }
};