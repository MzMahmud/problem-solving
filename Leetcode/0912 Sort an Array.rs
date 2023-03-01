impl Solution {
    pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
        let end = nums.len() - 1;
        let mut a = nums;
        merge_sort(&mut a, 0, end);
        a
    }
}

fn merge_sort(a: &mut Vec<i32>, start: usize, end: usize) {
    let n = end - start + 1;
    if n < 2 {
        return
    }
    let mid = start + (end - start) / 2;
    merge_sort(a, start, mid);
    merge_sort(a, mid + 1, end);
    merge(a, start, mid, end);
}

fn merge(a: &mut Vec<i32>, start: usize, mid: usize, end: usize) {
    let n = end - start + 1;
    let mut merged = vec![0; n];
    let (mut i, mut j, mut k) = (start, mid + 1, 0);
    while i <= mid && j <= end {
        if a[j] < a[i] {
            merged[k] = a[j];
            j += 1;
        } else {
            merged[k] = a[i];
            i += 1;
        }
        k += 1;
    }
    while i <= mid {
        merged[k] = a[i];
        i += 1;
        k += 1;
    }
    while j <= end {
        merged[k] = a[j];
        j += 1;
        k += 1;
    }

    i = start;
    for v in merged {
        a[i] = v;
        i += 1;
    }
}