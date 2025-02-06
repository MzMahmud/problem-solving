function tupleSameProduct(nums: number[]): number {
    const prods = new Map<number, number>();
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            const prod = nums[i] * nums[j];
            const count = (prods.get(prod) ?? 0) + 1;
            prods.set(prod, count);
        }
    }
    let toupleCount = 0;
    for (const pairCount of prods.values()) {
        const count = pairCount * (pairCount - 1) * 4;
        toupleCount += count;
    }
    return toupleCount;
}
