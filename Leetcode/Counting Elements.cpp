class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> seen;
        for(int num : arr)
            seen.insert(num);
        
        int count = 0;
        for(int num : arr)
            if(seen.find(num + 1) != seen.end())
                ++count;
        
        return count;
    }
};