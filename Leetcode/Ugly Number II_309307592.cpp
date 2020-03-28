
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <long long, vector<long long>, greater<long long> > minHeap;
        minHeap.push((long long)1);
        
        unordered_set<long long> uglys;
        
        int i = 0;
        long long ugly;
        while(i < n){
            ugly = minHeap.top();
            minHeap.pop();
            
            long long u[3] = {ugly * 2,
                              ugly * 3,
                              ugly * 5};
            
            for(auto num : u)
                // if does not exist 
                if(uglys.find(num) == uglys.end()){
                    minHeap.push(num);
                    uglys.insert(num);
                }
            i++;
        }
        return ugly;
    }
};
