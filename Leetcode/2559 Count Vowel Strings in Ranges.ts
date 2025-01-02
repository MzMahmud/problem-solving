function vowelStrings(words: string[], queries: number[][]): number[] {
    const counts = Array.from({ length: words.length }, () => 0);
    let count = 0;
    for (let i = 0; i < words.length; i++) {
        count += Number(isVowelString(words[i]));
        counts[i] = count;
    }
    const ans: number[] = [];
    for (const [l, r] of queries) {
        const count = counts[r] - (counts[l - 1] ?? 0);
        ans.push(count);
    }
    return ans;
}

function isVowelString(s: string) {
    const len = s.length;
    if (len == 0) return true;
    if (!"aeiuo".includes(s[0])) return false;
    if (!"aeiuo".includes(s[len - 1])) return false;
    return true;
}
