class Solution {
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged_intervals;
        bool inserted = false;
        for(int i = 0;i <= intervals.size();) {
            bool is_array_over = (i == intervals.size());
            bool can_insert_new_interval = (not inserted) and (is_array_over or newInterval[0] < intervals[i][0]);
            if(can_insert_new_interval) {
                merge(merged_intervals, newInterval);
                inserted = true;
            } else {
                if(!is_array_over) {
                    merge(merged_intervals, intervals[i]);                    
                }
                ++i;                
            }
        }
        return merged_intervals;
    }
};
