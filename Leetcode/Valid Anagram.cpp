class Solution {
public:
    bool isAnagram(string s, string t) {
        int char_count[26] = {};
        
        for(char c : s) char_count[c - 'a']++;
        
        for(char c : t) char_count[c - 'a']--;
        
        for(int i = 0;i < 26;++i)
            if(char_count[i])
                return false;
        
        return true;
    }
};