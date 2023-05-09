function isHappy(n: number): boolean {
    while (n !== 1 && n !== 89) {
        let digitSquareSum = 0;
        for (const d of `${n}`) {
            const digit = parseInt(d);
            digitSquareSum += digit * digit;
        }
        n = digitSquareSum;
    }
    return n === 1;
}
