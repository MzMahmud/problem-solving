function getLucky(s: string, k: number): number {
    let sum = 0;
    for (const c of s) {
        sum += getDigitSum(c.charCodeAt(0) - 'a'.charCodeAt(0) + 1);
    }
    for (let i = 1; i < k; i++) {
        sum = getDigitSum(sum);
    }
    return sum;
}

function getDigitSum(n: number): number {
    let sum = 0;
    while (n > 0) {
        sum += n % 10;
        n = Math.trunc(n / 10);
    }
    return sum;
}
