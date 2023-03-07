impl Solution {
    pub fn minimum_time(times: Vec<i32>, total_trips: i32) -> i64 {
        let total_trips = total_trips as i64;
        let min_time = (*times.iter().min().unwrap()) as i64;
        let mut lo = min_time;
        let mut hi = min_time * total_trips;
        while lo <= hi {
            let mid = (lo + hi) / 2;
            if Self::can_make_trips(mid, &times, total_trips) {
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        lo
    }

    fn can_make_trips(time: i64, times: &Vec<i32>, total_trips: i64) -> bool {
        let trips: i64 = times.iter()
                              .map(|t| time / (*t as i64))
                              .sum();
        trips >= total_trips
    }
}