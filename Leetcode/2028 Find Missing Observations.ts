function missingRolls(rolls: number[], mean: number, n: number): number[] {
    const m = rolls.length;
    const sumM = rolls.reduce((a, b) => a + b, 0);
    const sumN = mean * (m + n) - sumM;
    if (sumN < n || sumN > 6 * n) return [];
    const roll = Math.floor(sumN / n);
    const missings = Array.from({ length: n }, () => roll);
    const remainder = sumN % n;
    for (let i = 0; i < remainder; i++) missings[i]++;
    return missings;
}
