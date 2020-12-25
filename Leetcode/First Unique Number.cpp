class FirstUnique {
    unordered_map<int,int> freq;
    queue<int> q;
public:
    FirstUnique(vector<int>& a) {
        for(int n : a)
            add(n);
    }
    
    int showFirstUnique() {
        while(!q.empty() && freq[q.front()] >= 2)
            q.pop();
        if(q.empty()) return -1;
        return q.front();
    }
    
    void add(int n) {
        ++freq[n];
        q.push(n);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */