function numIdenticalPairs(nums: number[]): number {
    const count = new Map<number, number>();
    for (const n of nums) {
        count.set(n, (count.get(n) ?? 0) + 1);
    }
    let pairs = 0;
    for (const n of count.values()) {
        pairs += (n * (n - 1)) / 2;
    }
    return pairs;
}
