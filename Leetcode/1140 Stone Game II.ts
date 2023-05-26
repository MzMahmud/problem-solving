function stoneGameII(piles: number[]): number {
    const cache = new Map<string, number>();
    function dfs(player: number, i: number, m: number): number {
        if (i >= piles.length) {
            return 0;
        }
        const key = `${player}-${i}-${m}`;
        if (cache.has(key)) {
            return cache.get(key) as number;
        }
        let score = player == 0 ? -Infinity : Infinity, stones = 0;
        const maxJ = Math.min(2 * m, piles.length - i);
        for (let j = 1; j <= maxJ; j++) {
            stones += piles[i + j - 1];
            const nextM = Math.max(m, j), nextI = i + j;
            if (player == 0) {
                score = Math.max(score, stones + dfs(1, nextI, nextM));
            }
            else {
                score = Math.min(score, dfs(0, nextI, nextM));
            }
        }
        cache.set(key, score);
        return score;
    }
    return dfs(0, 0, 1);
}
