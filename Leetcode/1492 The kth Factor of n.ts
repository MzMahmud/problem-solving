// O(sqrt n) time, O(1) space
function kthFactor(n: number, k: number): number {
    const sqrt = Math.floor(Math.sqrt(n));
    for (let d = 1; d <= sqrt; d++) {
        if (n % d === 0 && --k === 0) {
            return d;
        }
    }
    for (let d = sqrt; d >= 1; d--) {
        if (n % d === 0) {
            const otherD = n / d;
            if (d != otherD && --k === 0) {
                return otherD;
            }
        }
    }
    return -1;
}

// O(sqrt n) time, O(sqrt n) space
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
