function stoneGameIII(values: number[]): string {
    const cache = new Array<number>(values.length).fill(Infinity);
    function dfs(i: number): number {
        if (i >= values.length) {
            return 0;
        }
        if (cache[i] !== Infinity) {
            return cache[i];
        }
        let score = 0, optScore = -Infinity;
        for (let j = i; j < Math.min(i + 3, values.length); j++) {
            score += values[j];
            optScore = Math.max(optScore, score - dfs(j + 1));
        }
        return cache[i] = optScore;
    }
    const score = dfs(0);
    return score < 0 ? "Bob" : score === 0 ? "Tie" : "Alice";
}
