function minPartitions(n: string): number {
    let maxDigit = 0;
    for (const digit of n) {
        maxDigit = Math.max(maxDigit, parseInt(digit));
    }
    return maxDigit;
}
