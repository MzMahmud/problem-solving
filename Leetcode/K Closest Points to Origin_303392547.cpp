struct Point {
    double x, y, dist;
    Point(double _x = .0, double _y = .0) {
        x    = _x;
        y    = _y;
        dist = sqrt(x * x + y * y);
    }
};

class Cmp {
  public:
    bool operator()(Point a, Point b) { return a.dist < b.dist; }
};



class Solution {  
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        priority_queue<Point, vector<Point>, Cmp> maxHeap;

        for (auto point : points) {
            Point p(point[0], point[1]);
            if (maxHeap.size() < K)
                maxHeap.push(p);
            else if (p.dist < maxHeap.top().dist) {
                maxHeap.push(p);
                if (maxHeap.size() > K)
                    maxHeap.pop();
            }
        }
        vector<vector<int>> retPoints;
        while (!maxHeap.empty()) {
            auto p = maxHeap.top();maxHeap.pop();
            retPoints.push_back({(int)p.x, (int)p.y});
        }
        return retPoints;
    }
};
