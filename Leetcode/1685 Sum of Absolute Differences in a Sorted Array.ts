function getSumAbsoluteDifferences(nums: number[]): number[] {
    const n = nums.length;
    const suffixSum = new Array<number>(n + 1);
    suffixSum[n] = 0;
    for (let i = n - 1; i >= 0; i--) {
        suffixSum[i] = nums[i] + suffixSum[i + 1];
    }
    let prefixSum = 0;
    const sums = new Array<number>(n);
    for (let i = 0; i < n; i++) {
        prefixSum += nums[i];
        sums[i] = (2 * i + 2 - n) * nums[i] - prefixSum + suffixSum[i + 1];
    }
    return sums;
}
