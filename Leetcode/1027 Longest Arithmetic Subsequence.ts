function longestArithSeqLength(nums: number[]): number {
    const sequences = new Array<Map<number, number>>(nums.length);
    let maxLen = 0;
    for (let right = 0; right < nums.length; right++) {
        sequences[right] = new Map<number, number>();
        for (let left = 0; left < right; left++) {
            const diff = nums[left] - nums[right];
            const seqLen = 1 + (sequences[left].get(diff) ?? 1);
            sequences[right].set(diff, seqLen);
            maxLen = Math.max(maxLen, seqLen);
        }
    } 
    return maxLen;
}
