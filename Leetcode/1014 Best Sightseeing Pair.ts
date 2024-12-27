function maxScoreSightseeingPair(values: number[]): number {
    let maxLeftScore = values[0], maxScore = 0;
    for (let i = 1; i < values.length; i++) {
        const currRightScore = values[i] - i;
        maxScore = Math.max(maxScore, maxLeftScore + currRightScore);
        const currLeftScore = values[i] + i;
        maxLeftScore = Math.max(maxLeftScore, currLeftScore);
    }
    return maxScore;
}
