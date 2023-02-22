class Solution {
  public:
    int shipWithinDays(const vector<int> &weights, int days) {
        int lo = 0, hi = 0;
        // O(n) time
        for (int weight : weights) {
            lo = max(lo, weight);
            hi += weight;
        }
        int capacity = 0;
        // loop runs at most O(log s) time
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // O(n) time
            if (canShip(mid, weights, days)) {
                capacity = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // so the loop runs in O(n log s) time
        return capacity;
    }

  private:
    bool canShip(int capacity, const vector<int> &weights, int maxDays) {
        int days = 1, weightSum = 0;
        for (int weight : weights) {
            if (weightSum + weight > capacity) {
                days++;
                weightSum = 0;
            }
            weightSum += weight;
        }
        return days <= maxDays;
    }
};