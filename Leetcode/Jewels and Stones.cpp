class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> count;
        for(char c : S)
            count[c]++;
        
        int ans = 0;
        for(char c : J)
            ans += count[c];
        
        return ans;
    }   
};