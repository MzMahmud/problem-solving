class Solution {
public:
    double angleClock(int h, int m) {
        double angle = .5*abs(60.0*h - 11.0*m);
        return angle > 180 ? 360 - angle : angle;
    }
};
