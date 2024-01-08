function minOperations(nums: number[]): number {
    const frequencies = new Map<number, number>();
    for (const n of nums) {
        frequencies.set(n, (frequencies.get(n) ?? 0) + 1);
    }
    let operations = 0;
    for (const freq of frequencies.values()) {
        if (freq === 1) {
            return -1;
        }
        operations += Math.ceil(freq / 3); 
    }
    return operations;
}
