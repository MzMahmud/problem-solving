class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long window_sum = 0;
        for(int i = 0;i < k;++i) {
            window_sum += arr[i];
        }
        const long long THRESHOLD_SUM = (long long) k *  threshold;
        int sub_array_count = (window_sum >= THRESHOLD_SUM);
        for(int i = k;i < arr.size();++i) {
            window_sum += (arr[i] - arr[i - k]);
            if(window_sum >= THRESHOLD_SUM) {
                ++sub_array_count;
            }
        }
        return sub_array_count;
    }
};
