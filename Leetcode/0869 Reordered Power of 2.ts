// compute on every call O((log n)^2)
function reorderedPowerOf2(n: number): boolean {
    const digitCountN = getDigitCount(n);
    let powerOf2 = 1;
    for (let i = 0; i < 32; i++) {
        if (arrayEqual(digitCountN, getDigitCount(powerOf2))) {
            return true;
        }
        powerOf2 <<= 1;
    }
    return false;
}

function getDigitCount(n: number) {
    const digitCount = new Array<number>(10).fill(0);
    while (n > 0) {
        digitCount[n % 10]++;
        n = Math.floor(n / 10);
    }
    return digitCount;
}

function arrayEqual(a: number[], b: number[]) {
    if (a.length !== b.length) {
        return false;
    }
    for (let i = 0; i < a.length; i++) {
        if (a[i] !== b[i]) {
            return false;
        }
    }
    return true;
}
                                 
// precompute power of 2 anagram
const powerOf2AnagramsByLength = (() => {
    const MAX_VAL = 1_000_000_000;
    const byLen = new Map<number, Set<string>>();
    for (let powerOf2 = 1; powerOf2 <= MAX_VAL; powerOf2 <<= 1) {
        const val = normalize(powerOf2);
        const group = byLen.get(val.length) ?? new Set<string>();
        group.add(val);
        byLen.set(val.length, group); 

    }
    return byLen;
})();

function reorderedPowerOf2(n: number): boolean {
    const normal = normalize(n);
    const powerOf2Anagrams = powerOf2AnagramsByLength.get(normal.length) ?? new Set<string>();
    return powerOf2Anagrams.has(normal); 
}

function normalize(n: number) {
    return `${n}`.split('').sort().join('');
}
