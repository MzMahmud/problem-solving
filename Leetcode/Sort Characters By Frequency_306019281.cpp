struct Pair{
    char ch;
    int freq;
    Pair(char c,int f):ch(c),freq(f){}
    
    bool operator<(const Pair& other) const { 
        return freq > other.freq;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char ch : s)
            freq[ch]++;
        
        auto it = freq.begin();
        
        vector<Pair> v;
        string out = "";
        while(it != freq.end()){
            v.emplace_back(it->first,it->second);
            it++;
        }
        
        sort(v.begin(),v.end());
        
        for(Pair p : v){
            while(p.freq--){
                out += p.ch;
            }
        }
        
        return out;
    }
};
