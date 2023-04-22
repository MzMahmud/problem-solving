function minInsertions(s: string): number {
    const cache = new Array<number[]>(s.length);
    for (let i = 0; i < cache.length; i++) {
        cache[i] = new Array<number>(s.length).fill(-1);
    }
    function minInserts(i: number, j: number): number {
        if (i > j) {
            return 0;
        }
        if (cache[i][j] !== -1) {
            return cache[i][j];
        }
        if (s[i] === s[j]) {
            cache[i][j] = minInserts(i + 1, j - 1);
        } else {
            cache[i][j] = 1 + Math.min(minInserts(i + 1, j), minInserts(i, j - 1));
        }
        return cache[i][j];
    }
    return minInserts(0, s.length - 1);
}
