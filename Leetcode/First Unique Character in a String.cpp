class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {};
        
        for(char c : s){
            freq[c - 'a']++;
        }
        
        int ret = -1;
        for(int i = 0;i < s.size();i++){
            if(freq[s[i] - 'a']== 1){
                ret = i;
                break;
            }
        }
        return ret;
    }
};
