struct Pair{
   string elem;
    int freq;
   
   Pair(string e = "",int f = 0) : elem(e),freq(f){}
   
   bool operator<(const Pair& other) const {
       return freq == other.freq? (elem > other.elem) : (freq < other.freq);  
   }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string,int> freq;
        
        for(auto str : words)
            freq[str]++;

        priority_queue<Pair> pq;

        auto it = freq.begin();
        while(it != freq.end()){
            pq.push(Pair(it->first,it->second));
            it++;
        }

        vector<string> out;
        while(k-- && !pq.empty()){
            out.push_back(pq.top().elem);
            pq.pop();
        }

        return out;
    }
};


