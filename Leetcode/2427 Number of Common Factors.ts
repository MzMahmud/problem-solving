function commonFactors(a: number, b: number): number {
    return nFactors(gcd(a, b));
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}

function nFactors(n: number): number {
    let factors = 0;
    for (let d = 1; d * d <= n; d++) {
        if (n % d === 0) {
            factors++;
            const otherD = n / d;
            if (d !== otherD) {
                factors++;
            }
        }
    }
    return factors;
}
