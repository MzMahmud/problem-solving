impl Solution {
    // O(log n) time, O(1) space
    pub fn find_kth_positive(array: Vec<i32>, k: i32) -> i32 {
        let (mut last_missing, mut n_missing) = (1, 0);
        let (mut lo, mut hi) = (0, array.len() as i32 - 1);
        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            let n = array[mid as usize];
            let new_n_missing = n - mid - 1;
            if new_n_missing < k {
                lo = mid + 1;
                n_missing = new_n_missing;
                last_missing = n + 1;
            } else {
                hi = mid - 1;
            }
        }
        last_missing + k - n_missing - 1
    }

    // O(n) time, O(1) space
    pub fn find_kth_positive(array: Vec<i32>, k: i32) -> i32 {
        let mut last_missing = 1;
        let mut n_missing = 0;
        for n in array {
            let new_n_missing = n_missing + n - last_missing;
            if new_n_missing >= k {
                break
            }
            n_missing = new_n_missing;
            last_missing = n + 1;
        }
        last_missing + k - n_missing - 1
    }
}