function bitwiseComplement(n: number): number {
    if (n === 0) return 1;
    let mask = -1; // all 1
    while(n & mask) mask <<= 1;
    return ~n & ~mask;
}
