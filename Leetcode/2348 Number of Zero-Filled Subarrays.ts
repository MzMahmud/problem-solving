function zeroFilledSubarray(nums: number[]): number {
    let lastIndex = -1, lastSize = 0;
    let subarrayCount = 0;
    for(let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            continue;
        } 
        lastSize = (lastIndex + 1) === i ? (lastSize + 1) : 1;
        subarrayCount += lastSize;
        lastIndex = i;
    }
    return subarrayCount;
};
