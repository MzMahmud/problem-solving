class Solution {
    static bool compare_interval(const vector<int> &a, const vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    
    void merge(vector<vector<int>>& intervals, const vector<int>& new_interval) {
        if(intervals.empty()) {
            intervals.push_back(new_interval);
            return;
        }
        auto &last_interval = intervals.back();
        if(last_interval[1] < new_interval[0]) {
            intervals.push_back(new_interval);
        } else {
            last_interval[1] = max(last_interval[1], new_interval[1]);
        }
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare_interval);
        vector<vector<int>> merged_intervals;
        for(const auto &interval : intervals) {
            merge(merged_intervals, interval);
        }
        return merged_intervals;
    }
};
