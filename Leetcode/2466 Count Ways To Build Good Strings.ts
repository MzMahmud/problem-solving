const MOD = 1_000_000_007;

function countGoodStrings(low: number, high: number, zero: number, one: number): number {
    const nGoodStrs = new Array<number>(high + 1).fill(0);
    nGoodStrs[0] = 1;
    for (let l = 0; l <= high; l++) {
        const nextZero = l + zero;
        if (nextZero <= high) {
            nGoodStrs[nextZero] = (nGoodStrs[nextZero] + nGoodStrs[l]) % MOD;
        }
        const nextOne = l + one;
        if (nextOne <= high) {
            nGoodStrs[nextOne] = (nGoodStrs[nextOne] + nGoodStrs[l]) % MOD;
        }
    }
    let goodStrs = 0;
    for (let l = low; l <= high; l++) {
        goodStrs = (goodStrs + nGoodStrs[l]) % MOD;
    }
    return goodStrs;
}
