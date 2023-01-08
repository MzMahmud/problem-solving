class Solution {
    int find_hours_to_eat(const vector<int>& piles, int hourly_rate) {
        int hours_to_eat = 0;
        for(const int &bananas_count : piles) {
            hours_to_eat += (bananas_count/hourly_rate) + (bananas_count % hourly_rate != 0);
        }
        return hours_to_eat;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1;
        for(const int &bananas_count : piles) {
            hi = max(hi, bananas_count);
        }
        int hours_to_eat, mid;
        while(lo < hi) {
            mid = (hi + lo) >> 1;
            hours_to_eat = find_hours_to_eat(piles, mid);
            if(hours_to_eat > h) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return hi;
    }
};
