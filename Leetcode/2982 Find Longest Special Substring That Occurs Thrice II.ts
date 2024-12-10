function maximumLength(s: string): number {
    const counts: number[][] = Array.from({ length: 26 }, () => []);
    let maxLen = -1;
    const updateCounts = (ch: string, count: number) => {
        const index = ch.charCodeAt(0) - 'a'.charCodeAt(0);
        for (let i = 0; i < count; i++) {
            counts[index][i] = (counts[index][i] ?? 0) + count - i;
            if (counts[index][i] >= 3) {
                maxLen = Math.max(maxLen, i + 1);
            }
        }
    };
    for (let i = 0, j = 0; j <= s.length; j++) {
        if (j === s.length || s[i] !== s[j]) {
            updateCounts(s[i], j - i);
            i = j;
        }
    }
    return maxLen;
}
