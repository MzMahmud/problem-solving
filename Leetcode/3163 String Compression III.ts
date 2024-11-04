function compressedString(word: string): string {
    let compressed = "";
    let lastChar = "", lastCharCount = 0;
    for (const ch of word) {
        if (ch === lastChar) {
            lastCharCount++;
        } else {
            if (lastCharCount > 0) {
                compressed += `${lastCharCount}${lastChar}`;
            }
            lastChar = ch;
            lastCharCount = 1;
        }
        if (lastCharCount === 9) {
            compressed += `9${lastChar}`;
            lastCharCount -= 9;
        }
    }
    if (lastCharCount > 0) {
        compressed += `${lastCharCount}${lastChar}`;
    }
    return compressed;
}
