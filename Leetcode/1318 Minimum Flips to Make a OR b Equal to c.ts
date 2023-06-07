function minFlips(a: number, b: number, c: number): number {
    let flips: number = 0;
    for (; a || b || c; a >>= 1, b >>= 1, c >>= 1) {
        if (c & 1) {
            if (!(a & 1 || b & 1)) flips++;
        } else {
            if (a & 1 && b & 1) flips += 2;
            else if (a & 1 || b & 1) flips += 1;
        }
    }
    return flips;
}
