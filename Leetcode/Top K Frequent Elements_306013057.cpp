struct Pair{
   int num,freq;
   
   Pair(int n = 0,int f = 0) : num(n),freq(f){}
   
   bool operator<(const Pair& other) const {
       return freq < other.freq;  
   }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        
        for(int num : nums)
            freq[num]++;

        priority_queue<Pair> pq;

        auto it = freq.begin();
        while(it != freq.end()){
            pq.push(Pair(it->first,it->second));
            it++;
        }

        vector<int> out;
        while(k-- && !pq.empty()){
            out.push_back(pq.top().num);
            pq.pop();
        }

        return out;
    }
};

