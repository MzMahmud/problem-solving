function sumZero(n: number): number[] {
    const nums: number[] = n % 2 === 0 ? [] : [0];
    const halfN = n >> 1;
    for (let i = 1; i <= halfN; i++) {
        nums.push(i);
        nums.push(-i);
    }
    return nums;
}
