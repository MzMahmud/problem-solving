function superPow(a: number, b: number[]): number {
    return superPower(a, b, b.length - 1, 1337);
}

function superPower(a: number, b: number[], index: number, mod: number): number {
    if (index < 0) return 1 % mod;
    const p = b[index];
    const sub = superPower(a, b, index - 1, mod);
    const res = (powerMod(sub, 10, mod) * powerMod(a, p, mod)) % mod;
    return res;
}

function powerMod(a: number, b: number, m: number): number {
    if (b === 0) return 1 % m;
    let res = powerMod(a, b >> 1, m);
    res = (res * res) % m;
    if (b % 2 === 1) res = (res * a) % m;
    return res;
}
