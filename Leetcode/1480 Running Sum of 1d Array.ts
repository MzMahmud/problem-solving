function runningSum(nums: number[]): number[] {
    let runSum = 0;
    return nums.map(num => runSum += num);
}
