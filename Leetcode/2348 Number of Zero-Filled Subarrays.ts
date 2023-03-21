function zeroFilledSubarray(nums: number[]): number {
    let totalCount = 0, currentCount = 0;
    for(const num of nums) {
        if(num === 0) {
            currentCount++;
        } else {
            currentCount = 0;
        }
        totalCount += currentCount;
    }
    return totalCount;
};
