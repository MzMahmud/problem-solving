function hasAlternatingBits(n: number): boolean {
    let expected = n & 1;
    while (n > 0) {
        const lastBit = n & 1;
        if (lastBit !== expected) {
            return false;
        }
        expected ^= 1;
        n >>>= 1;
    }
    return true;
}
