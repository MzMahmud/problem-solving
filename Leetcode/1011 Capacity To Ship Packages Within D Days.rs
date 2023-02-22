impl Solution {
    pub fn ship_within_days(weights: Vec<i32>, days: i32) -> i32 {
        let (mut lo, mut hi) = (0, 0);
        for &weight in &weights {
            lo = std::cmp::max(lo, weight);
            hi += weight;
        }
        let mut capacity = 0;
        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            if Self::can_ship(mid, &weights, days) {
                capacity = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        capacity
    }

    fn can_ship(capacity: i32, weights: &Vec<i32>, max_days: i32) -> bool {
        let (mut days, mut weight_sum) = (1, 0);
        for &weight in weights {
            if weight + weight_sum > capacity {
                days += 1;
                weight_sum = 0;
            }
            weight_sum += weight;
        } 
        days <= max_days
    }
}