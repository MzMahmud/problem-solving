function numTilePossibilities(tiles: string): number {
    const counts = Array.from({ length: 26 }, () => 0);
    for (const ch of tiles) {
        const idx = ch.charCodeAt(0) - 'A'.charCodeAt(0);
        counts[idx]++;
    }
    function dp(index: number, str: string) {
        if (index >= counts.length) {
            return str.length == 0 ? 0 : countPermutation(str);
        }
        let totalPerm = 0;
        for (let count = 0; count <= counts[index]; count++) {
            const ch = String.fromCharCode('A'.charCodeAt(0) + index);
            const nextStr = str + ch.repeat(count);
            totalPerm += dp(index + 1, nextStr);
        }
        return totalPerm;
    }
    return dp(0, "");
}

function countPermutation(str: string) {
    const counts = Array.from({ length: 26 }, () => 0);
    for (const ch of str) {
        const idx = ch.charCodeAt(0) - 'A'.charCodeAt(0);
        counts[idx]++;
    }
    let perp = fact(str.length);
    for (const count of counts) {
        perp /= fact(count);
    }
    return perp;
}

function fact(n: number): number {
    return n === 0 ? 1 : n * fact(n - 1);
}
