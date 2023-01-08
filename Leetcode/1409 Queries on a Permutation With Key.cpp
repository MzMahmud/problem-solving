class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        list<int> li;
        for(int i = 1;i <= m;++i)
            li.push_back(i);
        
        vector<int> out;
        
        for(auto q : queries){
            int i = 0;
            for(auto it = li.begin();it != li.end();++it,++i){
                if(*it == q){
                    out.push_back(i);
                    break;
                }
            }
            li.remove(q);
            li.push_front(q);
        }
        return out;
    }
};