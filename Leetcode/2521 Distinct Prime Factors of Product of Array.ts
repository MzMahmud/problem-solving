function distinctPrimeFactors(nums: number[]): number {
    const primes = new Set<number>();
    for (const n of nums) {
        pickPrimeFactor(n, primes);
    }
    return primes.size;
}

function pickPrimeFactor(n: number, primes: Set<number>) {
    for (let d = 2; d * d <= n; d++) {
        if (n % d != 0) continue;
        while (n % d == 0) n /= d;
        primes.add(d);
    }
    if (n > 1) primes.add(n);
}
