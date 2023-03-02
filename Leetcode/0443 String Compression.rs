impl Solution {
    pub fn compress(chars: &mut Vec<char>) -> i32 {
        let (mut i, mut k) = (0, 0);
        let n = chars.len();
        for j in 0..=n {
            if j == n || chars[i] != chars[j] {
                chars[k] = chars[i];
                k += 1;
                let run_len = j - i;
                if run_len > 1 {
                    for d in run_len.to_string().chars() {
                        chars[k] = d;
                        k += 1
                    }
                }
                i = j;
            }
        }
        k as i32
    }
}