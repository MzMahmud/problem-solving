struct pii{
    int k,v;
    pii(int key,int val) : k(key),v(val){}
};

class LRUCache {
    unordered_map<int,list<pii>::iterator> addr;
    list<pii> q;
    int cap;
    
public:
    LRUCache(int capacity) {
        cap  = capacity;
    }
    
    int get(int key) {
        if(addr.find(key) == end(addr))
            return -1;
        
        int val = addr[key]->v;
        
        q.erase(addr[key]);
        addr.erase(key);
        put(key,val);
        
        return val;
    }
    
    void put(int key, int val) {
        if(addr.find(key) != end(addr)){
            q.erase(addr[key]);
            addr.erase(key);
        }
            
        
        if(q.size() == cap){
            // cout << "del " << *q.rbegin() << endl; 
            addr.erase(q.rbegin()->k);
            q.pop_back();
        }
        
        q.emplace_front(key,val);
        addr[key] = begin(q);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */