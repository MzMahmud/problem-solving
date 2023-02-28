impl Solution {
    pub fn count_even(num: i32) -> i32 {
        (2..=num)
            .filter(is_digit_sum_even)
            .count() as i32
    }
}

fn is_digit_sum_even(n: &i32) -> bool {
    let digit_sum: i32 = 
        n.to_string()
         .chars()
         .filter_map(|c| c.to_digit(10))
         .map(|d| d as i32)
         .sum();
    digit_sum % 2 == 0
}