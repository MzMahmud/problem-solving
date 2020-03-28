class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];

        string prefix = "";

        int min_len = -1;

        for(string s : strs){
            if(min_len < 0 || s.size() < min_len)
                min_len = s.length();
        }

        for(int i = 0;i < min_len;i++){
            char iTH = strs[0][i];
            for(int j = 1;j < strs.size();j++)
                if(strs[j][i] != iTH)
                    return prefix;

            prefix += iTH;
        }

        return prefix;
    }
};
