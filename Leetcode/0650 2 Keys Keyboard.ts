function minSteps(n: number): number {
    const factorization = primeFactorize(n);
    return factorization.reduce((sum, [d, p]) => sum + d * p, 0);
}

function primeFactorize(n: number) {
    const factorization: [number, number][] = [];
    let p = 0
    for (; n % 2 == 0; p++) n /= 2;
    if (p != 0) factorization.push([2, p]);
    for (let d = 3; d * d <= n; d += 2) {
        let p = 0
        for (; n % d == 0; p++) n /= d;
        if (p != 0) factorization.push([d, p]);
    }
    if (n > 1) factorization.push([n, 1]);
    return factorization;
}

function minSteps(n: number): number {
    if (n == 1) return 0;
    const memo = new Map<string, number>();
    function dp(curLen: number, copyLen: number): number {
        if (curLen == n) return 0;
        if (curLen > n) return Infinity;
        const key = `${curLen}-${copyLen}`;
        if (!memo.has(key)) {
            const copySteps = 2 + dp(2 * curLen, curLen);
            const pasteSteps = 1 + dp(curLen + copyLen, copyLen);
            memo.set(key, Math.min(copySteps, pasteSteps));
        }
        return memo.get(key)!;
    }
    return 1 + dp(1, 1);
}
