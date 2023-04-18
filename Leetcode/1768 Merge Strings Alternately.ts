function mergeAlternately(word1: string, word2: string): string {
    let merged = "";
    const maxLen = Math.max(word1.length, word2.length);
    for (let i = 0, j = 0; i < maxLen; i++) {
        if (i < word1.length) {
            merged += word1[i];
        } 
        if (i < word2.length) {
            merged += word2[i];
        }
    }
    return merged;
}
