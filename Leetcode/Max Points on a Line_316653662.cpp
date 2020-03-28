struct Slope{
    int x,y;
    
    Slope() : x(0),y(0) {}
    Slope(int _x,int _y) : x(_x),y(_y){
        if(x < 0){
            x = -x;
            y = -y;
        }
        int g = __gcd(abs(x),abs(y));
        if(g){
            x /= g;
            y /= g;
        }
    }
    
    bool operator==(const Slope &other) const {
        return x == other.x && y == other.y;
    }
};

class SlopeHash{ 
public:  
    size_t operator()(const Slope &s) const { 
        return s.x ^ s.y; 
    } 
}; 

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        
        int ans = 1;
        for(int i = 0;i < points.size();i++){
            vector<int> center = points[i];
            unordered_map<Slope,int,SlopeHash> slopes;
            for(int j = 0;j < points.size();j++){
                vector<int> point = points[j];
                Slope slope = Slope(point[0] - center[0],
                                    point[1] - center[1]);
                slopes[slope]++;
            }
            for(auto count : slopes){
                Slope same = Slope(0,0);
                int val;
                if(count.first == same){
                    val = count.second;
                }else{
                    val = count.second + slopes[same];
                }
                
                ans = max(ans,val);
            }
        }
        return ans;
    }
};
