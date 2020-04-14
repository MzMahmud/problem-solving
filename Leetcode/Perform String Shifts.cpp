
class Solution {
    void shift_left(string &s,int n){
        while(n--){
            char first = s[0];
            s.erase(begin(s));
            s.push_back(first);
        }
    }
    
    void shift_right(string &s,int n){
        while(n--){
            char last = s[s.length()-1];
            s.pop_back();
            s.insert(begin(s),last);
        }
    }
public:
    string stringShift(string s, vector<vector<int>>& shifts) {
        int shift = 0;
        for(const auto &s : shifts)
            shift += (s[0] ? s[1] : -s[1]);
        
        if(shift > 0)
            shift_right(s,shift);
        else
            shift_left(s,-shift);

        return s;
    }
};