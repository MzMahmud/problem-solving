const VOWELS = new Set<string>(['a', 'e', 'i', 'o', 'u']);

function maxVowels(s: string, k: number): number {
    let maxVowels = 0, vowels = 0;
    for (let i = 0; i < s.length; i++) {
        if (VOWELS.has(s[i])) vowels++;
        if (i >= k && VOWELS.has(s[i - k])) vowels--;
        maxVowels = Math.max(maxVowels, vowels);
    }
    return maxVowels;
}
