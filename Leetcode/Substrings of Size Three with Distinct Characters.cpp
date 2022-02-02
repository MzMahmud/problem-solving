#define CHAR_SET_SIZE 26
#define GOOD_STR_SIZE 03

class Solution {
    inline int get_index(const char &c) {
        return c - 'a';
    }
    
    bool is_good_string(int char_count[CHAR_SET_SIZE]) {
        for(int i = 0;i < CHAR_SET_SIZE;++i) {
            if(char_count[i] > 1) {
                return false;
            }
        }
        return true;
    }
public:
    int countGoodSubstrings(string s) {
        if(s.size() < GOOD_STR_SIZE) {
            return 0;
        }
        int char_count[CHAR_SET_SIZE] = {};
        for(int i = 0;i < GOOD_STR_SIZE; ++i) {
            ++char_count[get_index(s[i])];
        }
        int good_string_count = 0;
        for(int i = 0, j = GOOD_STR_SIZE; j <= s.size();++i,++j) {
            if(is_good_string(char_count)) {
                ++good_string_count;
            }
            --char_count[get_index(s[i])];
            if(j < s.size()) {
                ++char_count[get_index(s[j])];   
            }
        }
        return good_string_count;
    }
};
