function selfDividingNumbers(left: number, right: number): number[] {
    const nums: number[] = [];
    for (; left <= right; left++) {
        if (isSelfDividing(left)) {
            nums.push(left);
        }
    }
    return nums;
}

function isSelfDividing(N: number): boolean {
    let n = N;
    while (n > 0) {
        const d = n % 10;
        if (d === 0 || N % d !== 0) {
            return false;
        }
        n = Math.floor(n / 10);
    }
    return true;
}
