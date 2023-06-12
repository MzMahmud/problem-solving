function summaryRanges(nums: number[]): string[] {
    if (nums.length === 0) {
        return [];
    }
    let start = nums[0], end = nums[0];
    const ranges: string[] = [];
    for (const num of nums) {
        if (num <= (end + 1)) {
            end += num === end + 1? 1 : 0;
        } else {
            ranges.push(start === end ? `${start}` : `${start}->${end}`);
            start = end = num;
        }
    }
    ranges.push(start === end ? `${start}` : `${start}->${end}`);
    return ranges;
}
