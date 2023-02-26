impl Solution {
    pub fn min_distance(from_word: String, to_word: String) -> i32 {
        let (n, m) = (from_word.len(), to_word.len());
        let mut edit_distance = vec![vec![0; m+1]; n+1];
        for i in 0..=n {
            edit_distance[i][0] = i as i32;
        }
        for j in 0..=m {
            edit_distance[0][j] = j as i32;
        }
        for (i, char_i) in from_word.chars().enumerate().map(|(i, c)| (i + 1, c)) {
            for (j, char_j) in to_word.chars().enumerate().map(|(j, c)| (j + 1, c)) {
                if char_i == char_j {
                    edit_distance[i][j] = edit_distance[i-1][j-1];
                } else {
                    edit_distance[i][j] = 1 + edit_distance[i][j-1].min(edit_distance[i-1][j]).min(edit_distance[i-1][j-1]);
                }
            }
        }
        edit_distance[n][m]
    }
}