function reversePrefix(word: string, ch: string): string {
    const chars = [...word];
    let i = 0, j = chars.findIndex(c => c === ch);
    for (;i < j; i++, j--) {
        const t = chars[i];
        chars[i] = chars[j];
        chars[j] = t;
    } 
    return chars.join("");
}
