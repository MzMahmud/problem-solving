class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x[3],y[3];
        for(int i = 0;i < 3;i++){
            x[i] = points[i][0];
            y[i] = points[i][1];
        }
        
        long long a = (y[0] - y[1])*(x[0] - x[2]);
        long long b = (x[0] - x[1])*(y[0] - y[2]);
        
        return a != b;
    }
};
