function kthFactor(n: number, k: number): number {
    const low: number[] = [], high: number[] = [];
    for (let d = 1; d * d <= n; d++) {
        if (n % d === 0) {
            low.push(d);
            const otherD = n / d;
            if (d !== otherD) {
                high.push(otherD);
            } 
        }
    }
    if (1 <= k && k <= low.length) {
        return low[k - 1];
    }
    k = high.length + low.length - k ;
    return k < 0 ? -1 : high[k]; 
}
