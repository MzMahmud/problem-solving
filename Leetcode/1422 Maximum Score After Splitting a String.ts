function maxScore(s: string): number {
    const zeros = Array.from(s, () => 0);
    let nZeros = 0;
    for (let i = 0; i < s.length; i++) {
        nZeros += s[i] === "0" ? 1 : 0;
        zeros[i] = nZeros;
    }
    let nOnes = 0, maxScore = 0;
    for (let i = s.length - 1; i > 0; i--) {
        nOnes += s[i] === "1" ? 1 : 0;
        const score = nOnes + zeros[i - 1];
        maxScore = Math.max(maxScore, score);
    }
    return maxScore;
}
