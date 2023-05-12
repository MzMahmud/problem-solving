function canCross(stones: number[]): boolean {
    const stoneByIndex = new Map<number, number>();
    const last = stones.length - 1;
    for (let i = 0; i <= last; i++) {
        stoneByIndex.set(stones[i], i);
    }
    const cache = new Map<string, boolean>();
    function dfs(i: number, j: number): boolean {
        if (i > last) {
            return false;
        }
        if (i == last) {
            return true;
        }
        const key = `${i}-${j}`;
        if (cache.has(key)) {
            return cache.get(key) as boolean;
        }
        const steps = i === 0 ? [1] : [j - 1, j, j + 1];
        cache.set(key, false);
        for (const step of steps) {
            const nextI = stoneByIndex.get(stones[i] + step);
            if (nextI !== undefined && nextI > i && dfs(nextI, step)) {
                cache.set(key, true);
                break;
            }
        }
        return cache.get(key) as boolean;
    }
    return dfs(0, 0);
}
