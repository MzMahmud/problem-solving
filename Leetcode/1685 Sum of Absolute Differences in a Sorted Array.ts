function getSumAbsoluteDifferences(nums: number[]): number[] {
    const n = nums.length;
    const sums = new Array<number>(n);
    sums[n - 1] = nums[n - 1];
    for (let i = n - 2; i >= 0; i--) {
        sums[i] = nums[i] + sums[i + 1];
    }
    let prefixSum = 0;
    for (let i = 0; i < n; i++) {
        prefixSum += nums[i];
        sums[i] += (2 * i + 1 - n) * nums[i] - prefixSum;
    }
    return sums;
}
