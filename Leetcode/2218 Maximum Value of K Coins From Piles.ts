function maxValueOfCoins(piles: number[][], k: number): number {
    const cache: number[][] = new Array<number[]>(piles.length);
    for (let i = 0; i < cache.length; i++) {
        cache[i] = new Array<number>(k + 1).fill(-1);
    }
    return maxValue(0, k, cache, piles); 
}

function maxValue(i: number, k: number, cache: number[][], piles: number[][]): number {
    if (i === piles.length) {
        return 0;
    }
    if (cache[i][k] !== -1) {
        return cache[i][k];
    }
    cache[i][k] = maxValue(i + 1, k, cache, piles);
    let currentPile = 0;
    for(let j = 0; j < Math.min(k, piles[i].length); j++) {
        currentPile += piles[i][j];
        cache[i][k] = Math.max(
            cache[i][k],
            currentPile + maxValue(i + 1, k - j - 1, cache, piles)
        );
    }
    return cache[i][k];
}
