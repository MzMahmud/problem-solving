function addDigits(n: number): number {
    if (n === 0) return 0;
    const mod9 = n % 9;
    return mod9 === 0? 9: mod9;
}
