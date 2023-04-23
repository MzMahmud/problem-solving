const MOD = 1e9 + 7;

function numberOfArrays(s: string, k: number): number {
    const cache = new Array<number>(s.length).fill(-1);
    function dfs(i: number): number {
        if (i === s.length) {
            return 1;
        }
        if (cache[i] !== -1) {
            return cache[i];
        }
        if (s[i] === '0') {
            return cache[i] = 0;
        }
        let element = 0, nWays = 0;
        for (let j = i; j < s.length; j++) {
            element = 10 * element + parseInt(s[j]);
            if (element > k) {
                break;
            }
            nWays = (nWays + dfs(j + 1)) % MOD;
        }
        return cache[i] = nWays;
    }
    return dfs(0);
}
