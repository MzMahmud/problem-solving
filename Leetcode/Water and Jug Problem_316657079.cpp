class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > (x + y))
            return false;
        
        int g = __gcd(x,y);
        if(g == 0)
            return !z;
        return !(z % g);
    }
};
