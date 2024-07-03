function minDifference(nums: number[]): number {
    const n = nums.length;
    if (n <= 4) return 0;
    nums.sort((a, b) => a - b);
    let minDiff = Infinity;
    for (let left = 0, right = n - 4; left < 4; left++, right++) {
        minDiff = Math.min(minDiff, nums[right] - nums[left]);
    }
    return minDiff;
}
