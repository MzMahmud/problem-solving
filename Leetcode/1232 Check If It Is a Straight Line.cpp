struct Slope {
    int x, y;
    
    Slope(int _x, int _y) {
        x = abs(_x);
        y = abs(_y);
        int gcd = __gcd(x, y);
        bool make_x_neg = _x < 0 && _y > 0 || _x > 0 && _y < 0;
        if(gcd) {
            x /= gcd;
            y /= gcd; 
        }
        if(make_x_neg) {
            x = -x;
        } 
    }
    
    bool operator==(const Slope other) const {
        return x == other.x && y == other.y;
    }
    
    bool operator!=(const Slope other) const {
        return !(*this == other);
    }
};


Slope get_slope_from(const vector<int> &a, const vector<int> &b) {
    int del_x = a[0] - b[0];
    int del_y = a[1] - b[1];
    return Slope(del_x, del_y);
}

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        Slope common_slope = get_slope_from(coordinates[0], coordinates[1]);
        for(int i = 2;i < coordinates.size(); ++i) {
            Slope ith_slope = get_slope_from(coordinates[0], coordinates[i]);
            if(common_slope != ith_slope) {
                return false;
            }
        }
        return true;
    }
};
