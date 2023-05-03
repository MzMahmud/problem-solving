function intersection(nums: number[][]): number[] {
    const counts = new Array<number>(1001).fill(0);
    for (const arr of nums) {
        for (const num of arr) {
            counts[num]++;
        }
    }
    const intersect: number[] = [];
    for (let n = 0; n < counts.length; n++) {
        if (counts[n] === nums.length) {
            intersect.push(n);
        }
    }
    return intersect;
}
