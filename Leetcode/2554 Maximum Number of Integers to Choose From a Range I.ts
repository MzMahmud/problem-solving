function maxCount(banned: number[], n: number, maxSum: number): number {
    const bannedSet = new Set(banned);
    let count = 0, sum = 0;
    for (let i = 1; i <= n; i++) {
        if (bannedSet.has(i)) continue;
        if ((sum + i) <= maxSum) {
            count++;
            sum += i;
        }
    }
    return count;
}
