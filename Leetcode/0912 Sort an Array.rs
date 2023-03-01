impl Solution {
    pub fn sort_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut a = nums;
        let mut merged = vec![0; n];
        merge_sort(&mut a, 0, n - 1, &mut merged);
        a
    }
}

fn merge_sort(a: &mut Vec<i32>, start: usize, end: usize, merged: &mut Vec<i32>) {
    let n = end - start + 1;
    if n < 2 {
        return
    }
    let mid = start + (end - start) / 2;
    merge_sort(a, start, mid, merged);
    merge_sort(a, mid + 1, end, merged);
    merge(a, start, mid, end, merged);
}

fn merge(a: &mut Vec<i32>, start: usize, mid: usize, end: usize, merged: &mut Vec<i32>) {
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
    for m_i in 0..k {
        a[i] = merged[m_i];
        i += 1;
    }
}