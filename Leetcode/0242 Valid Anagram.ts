function isAnagram(s: string, t: string): boolean {
    const sCharCount = getCharCount(s), tCharCount = getCharCount(t);
    return sCharCount.every((c, i) => c === tCharCount[i]);
}

function getCharCount(s: string): number[] {
    const charCount = new Array<number>(26).fill(0);
    for (const c of s) {
        const idx = c.charCodeAt(0) - 'a'.charCodeAt(0);
        charCount[idx]++;
    }
    return charCount;
}
