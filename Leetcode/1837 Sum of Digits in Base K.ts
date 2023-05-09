function sumBase(n: number, k: number): number {
    let digitSum = 0;
    while (n > 0) {
        digitSum += (n % k);
        n = Math.floor(n / k);
    }
    return digitSum;
}
