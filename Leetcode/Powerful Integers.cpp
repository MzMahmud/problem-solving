class Solution {
    vector<int> p1; //stores all powers of x
    vector<int> p2; //stores all powers of y
    
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        p1.clear();
        p2.clear();
        
        if(x != 1)
        {
            for(int i = 1; i < bound; i *= x)
            {
            //stores all powers of x
                p1.push_back(i);
            }
        }
        else
        {
            p1.push_back(1);
        }
        
        if(y != 1)
        {
            for(int i = 1; i < bound; i *= y)
            {
            //stores all powers of y
                p2.push_back(i);
            }    
        }
        else
        {
            p2.push_back(1);
        }
        
        unordered_set<int> res;
        for(int  i = 0; i < p1.size(); i++)
        {
            for(int j = 0; j < p2.size(); j++)
            {
                int temp = p1[i] + p2[j];
                if(temp > bound) break;
                res.insert(temp);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
