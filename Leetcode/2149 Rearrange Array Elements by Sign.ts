function rearrangeArray(nums: number[]): number[] {
    const res: number[] = new Array(nums.length);
    let pi = 0, ni = 1;
    for (const n of nums) {
        if (n > 0) {
            res[pi] = n;
            pi += 2;
        } else {
            res[ni] = n;
            ni += 2;
        }
    }
    return res;
}
