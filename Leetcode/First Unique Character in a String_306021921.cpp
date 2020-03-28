class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;
        
        for(char c : s){
            freq[c]++;
        }
        
        int ret = -1;
        for(int i = 0;i < s.size();i++){
            if(freq[s[i]] == 1){
                ret = i;
                break;
            }
        }
        return ret;
    }
};
