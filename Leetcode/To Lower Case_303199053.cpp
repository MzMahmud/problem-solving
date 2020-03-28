class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0;i < str.size();i++)
            if('A' <= str[i] && str[i] <='Z')
                str[i] = str[i] | 1 << 5;
        return str;
    }
};
