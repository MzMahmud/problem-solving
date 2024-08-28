function camelMatch(queries: string[], pattern: string): boolean[] {
    return queries.map(s => isMatch(s, pattern));
}

function isMatch(s: string, pattern: string) {
    let i = 0;
    for (const c of s) {
        if (i < pattern.length && c == pattern[i]) {
            i++
        } else if (/[A-Z]/.test(c)) {
            return false;
        }
    }
    return i == pattern.length;
}
