class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> all;
        findOrientation(S,0,all);
        return all;
    }
    void findOrientation(string str, int cur_index,vector<string>& all) {
        if (cur_index == str.size()) {
            all.push_back(str);
            return;
        }
        
        findOrientation(str, cur_index + 1, all);
        
        if (is_alpha(str[cur_index])) {
            str[cur_index] ^= (1 << 5);//switch case
            findOrientation(str, cur_index + 1, all);
        }
    }
    
    bool is_alpha(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }

};
