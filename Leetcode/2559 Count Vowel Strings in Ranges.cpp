class Solution {
    set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};

    bool isVowelString(const string &s) {
        int len = s.length();
        if (len == 0) return false;
        return VOWELS.contains(s[0]) && VOWELS.contains(s[len - 1]); 
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> counts(words.size(), 0); 
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            count += isVowelString(words[i]);
            counts[i] = count;
        }
        vector<int> ans(queries.size(), 0); 
        int i = 0;
        for (const auto &query : queries) {
            int l = query[0], r = query[1];
            int count = counts[r] - (l > 0 ? counts[l - 1] : 0);
            ans[i++] = count;
        }
        return ans;
    }
};
