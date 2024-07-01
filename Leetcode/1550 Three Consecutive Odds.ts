function threeConsecutiveOdds(arr: number[]): boolean {
    let consecutiveOdds = 0;
    for (const n of arr) {
        if (n % 2 === 0) {
            consecutiveOdds = 0;
        } else {
            consecutiveOdds++;
        }
        if (consecutiveOdds === 3) {
            return true;
        }
    }
    return false;
}
