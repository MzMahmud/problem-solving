function hammingWeight(n: number): number {
    let oneBits = 0;
    while (n != 0) {
        oneBits += (n & 1);
        n >>>= 1;
    }
    return oneBits;
}
