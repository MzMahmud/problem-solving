function getMoneyAmount(n: number): number {
    const cache: (number | null)[][] = Array.from(
        { length: n + 1 },
        () => Array.from({ length: n + 1 }, () => null)
    );
    return calculate(1, n, cache);
}

function calculate(low: number, high: number, cache: (number | null)[][]): number {
    if (low >= high) return 0;
    if (cache[low][high] == null) {
        cache[low][high] = Infinity;
        for (let i = low; i <= high; i++) {
            const cost = i + Math.max(
                calculate(low, i - 1, cache),
                calculate(i + 1, high, cache)
            );
            cache[low][high] = Math.min(cache[low][high], cost);
        }
    }
    return cache[low][high];
}
