function prefixCount(words: string[], pref: string): number {
    return words.reduce((count, str) => count + Number(hasPrefix(str, pref)), 0);
}

function hasPrefix(str: string, prefix: string) {
    let i = 0;
    for (; i < str.length && i < prefix.length; i++) {
        if (str[i] != prefix[i]) return false;
    }
    return i == prefix.length;
}
