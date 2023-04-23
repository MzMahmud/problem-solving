const MOD = 1e9 + 7;
const NON_PRIMES = new Set<string>(['1', '4', '6', '8', '9']);

// O(n^2 k) time, O(nk) space
function beautifulPartitions(s: string, k: number, minLength: number): number {
    const cache = new Array<number[]>(s.length);
    for (let i = 0; i < cache.length; i++) {
        cache[i] = new Array<number>(k + 1).fill(-1);
    }
    function dfs(i: number, k: number): number {
        if (i === s.length) {
            return k === 0? 1 : 0;
        }
        if (cache[i][k] !== -1) {
            return cache[i][k];
        }
        if (NON_PRIMES.has(s[i]) || k === 0) {
            return cache[i][k] = 0;
        }
        cache[i][k] = 0;
        for (let j = i + minLength - 1; j < s.length; j++) {
            if (NON_PRIMES.has(s[j])) {
                cache[i][k] = (cache[i][k] + dfs(j + 1, k - 1)) % MOD;
            }
        }
        return cache[i][k];
    }
    return dfs(0, k);
}
