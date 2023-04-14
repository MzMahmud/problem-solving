// recurrsive solution
function longestPalindromeSubseq(s: string): number {
    const n = s.length;
    const cache = new Array<number[]>(n);
    for (let i = 0; i < n; i++) {
        cache[i] = new Array<number>(n).fill(0);
    }
    return lps(0, n - 1, s, cache);
}

function lps(i: number, j: number, s: string, cache: number[][]): number {
    if (cache[i][j] !== 0) {
        return cache[i][j];
    }
    if (i === j) {
        return cache[i][j] = 1;
    }
    if (i > j) {
        return cache[i][j] = 0;
    }
    if (s[i] == s[j]) {
        return cache[i][j] = 2 + lps(i + 1, j - 1, s, cache);
    }
    return cache[i][j] = Math.max(lps(i + 1, j, s, cache), lps(i, j - 1, s, cache));
}   
 
// bottom-up dp solution
function longestPalindromeSubseq(s: string): number {
    const n = s.length;
    const lps = new Array<number[]>(n);
    for (let i = 0; i < n; i++) {
        lps[i] = new Array<number>(n).fill(0);
    }
    for (let i = n - 1; i >= 0; i--) {
        lps[i][i] = 1;
        for (let j = i + 1; j < n; j++) {
            if (s[i] === s[j]) {
                lps[i][j] = 2 + lps[i + 1][j - 1];
            } else {
                lps[i][j] = Math.max(lps[i + 1][j], lps[i][j - 1]);
            }
        }
    }
    return lps[0][n - 1];
}
