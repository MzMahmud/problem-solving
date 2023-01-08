class Solution {
public:
    enum SerachType { FIRST, LAST };

    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums,target,FIRST),binarySearch(nums,target,LAST)};        
    }

    int binarySearch(vector<int> a, int val, SerachType type) {
        int lo = 0;
        int hi = (int)a.size() - 1;
        int mid;
        int index = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (a[mid] == val) {
                index = mid;
                if (type == FIRST)
                    hi = mid - 1;
                if (type == LAST)
                    lo = mid + 1;
            } else if (a[mid] < val)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return index;
    }
};
