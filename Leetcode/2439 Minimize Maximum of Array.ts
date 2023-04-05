function minimizeArrayValue(nums: number[]): number {
    let prefixSum = nums[0], maxValue = nums[0];
    for(let i = 1; i < nums.length; i++) {
        prefixSum += nums[i];
        const value = Math.ceil(prefixSum / (i + 1));
        maxValue = Math.max(maxValue, value);
    }
    return maxValue;
}
