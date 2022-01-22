class Solution {
    static bool compare_interval(const vector<int> &a, const vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare_interval);
        vector<vector<int>> merged_intervals;
        int i = 0, j = 0;
        int start = intervals[i][0], end = intervals[i][1];
        while(j < intervals.size()) {
            if(start <= intervals[j][0] && intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
                ++j;
            } else {
                merged_intervals.push_back({start, end});
                i = j;
                j = i;
                start = intervals[i][0], end = intervals[i][1];
            }
        }
        merged_intervals.push_back({start, end});
        return merged_intervals;
    }
};
