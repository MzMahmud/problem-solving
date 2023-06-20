function getAverages(nums: number[], k: number): number[] {
    if (k === 0) {
        return nums;
    }
    const n = nums.length, windowSize = 2 * k + 1;
    const avgs = new Array<number>(n).fill(-1);
    if (windowSize > n) {
        return avgs;
    }
    let windowSum = 0;
    for (let i = 0; i < (windowSize - 1); i++) {
        windowSum += nums[i];
    }
    for (let i = k; i < (n - k); i++) {
        windowSum += nums[i + k];
        avgs[i] = Math.floor(windowSum / windowSize);
        windowSum -= nums[i - k];
    }
    return avgs;
}
