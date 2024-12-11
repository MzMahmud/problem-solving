function maximumBeauty(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let maxLen = 0;
    for (let left = 0, right = 0; right < nums.length;) {
        if ((nums[right] - nums[left]) <= 2 * k) {
            right++;
        } else {
            left++;
        }
        maxLen = Math.max(maxLen, right - left);
    }
    return maxLen;
}
