function maximumLength(s: string): number {
    for (let len = s.length; len > 0; len--) {
        const specialCounts = new Map<string, number>();
        for (let i = 0;i <= s.length - len; i++) {
            const curr = s.substring(i, i + len);
            if (!isSpecial(curr)) continue;
            const count = (specialCounts.get(curr) ?? 0) + 1;
            if (count >= 3) return len;
            specialCounts.set(curr, count);
        }
    }
    return -1;   
}

function isSpecial(s: string) {
    if (s.length === 0) return true;
    const firstChar = s[0];
    for (const ch of s) {
        if (ch !== firstChar) {
            return false;
        }
    }
    return true;
}
