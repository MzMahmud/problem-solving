typedef vector<int> Interval;

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval> &first_list,
                                          vector<Interval> &second_list) {
        vector<Interval> interval_intersections;
        int i = 0, j = 0;
        while(i < first_list.size() && j < second_list.size()) {
            int start = max(first_list[i][0], second_list[j][0]);
            int end = min(first_list[i][1], second_list[j][1]);
            if(start <= end) {
                interval_intersections.push_back({start, end});
            }
            if(first_list[i][1] < second_list[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return interval_intersections;
    }
};
