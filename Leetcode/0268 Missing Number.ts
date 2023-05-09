function missingNumber(nums: number[]): number {
    return nums.reduce((missing, num, i) => missing ^ num ^ i, nums.length);
}
