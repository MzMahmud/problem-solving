#define CHAR_SET_SIZE 26

class Solution {
    inline int get_index(const char & c) {
        return c - 'a';
    } 
    
    void count_chars(string::iterator begin, string::iterator end, int out_char_count[CHAR_SET_SIZE]) {
        for(;begin != end;++begin) {
            ++out_char_count[get_index(*begin)];
        }
    }
    
    bool is_anagram(int a_char_count[CHAR_SET_SIZE], int b_char_count[CHAR_SET_SIZE]) {
        for(int i = 0;i < CHAR_SET_SIZE;++i) {
            if(a_char_count[i] != b_char_count[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n_s = s.size(), n_p = p.size();
        if(n_p > n_s) {
            return {};
        }
        int p_char_count[CHAR_SET_SIZE] = {};
        count_chars(begin(p), end(p), p_char_count);
        
        int s_char_count[CHAR_SET_SIZE] = {};
        count_chars(begin(s), begin(s) + n_p, s_char_count);
        
        vector<int> anagram_indices;
        for(int i = 0, j = n_p; j <= n_s;++i, ++j) {
            if(is_anagram(p_char_count, s_char_count)) {
                anagram_indices.push_back(i);
            }
            --s_char_count[get_index(s[i])];
            if(j < n_s) {
                ++s_char_count[get_index(s[j])];            
            }
        }
        return anagram_indices;
    }
};
