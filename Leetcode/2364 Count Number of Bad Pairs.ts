function countBadPairs(nums: number[]): number {
    const n = nums.length;
    const seenDiff = new Map<number, number>();
    let badCount = (n * (n - 1)) / 2;
    for (let i = 0; i < n; i++) {
        const diff = i - nums[i];
        const diffCount = seenDiff.get(diff) ?? 0;
        badCount -= diffCount;
        seenDiff.set(diff, diffCount + 1);
    }
    return badCount;
}
