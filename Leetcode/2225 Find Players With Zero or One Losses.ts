function findWinners(matches: number[][]): number[][] {
    const lostMatchesCount = new Map<number, number>();
    for (const [winner, loser] of matches) {
        if (!lostMatchesCount.has(winner)) lostMatchesCount.set(winner, 0);
        if (!lostMatchesCount.has(loser)) lostMatchesCount.set(loser, 0);
        lostMatchesCount.set(loser, (lostMatchesCount.get(loser) ?? 0) + 1);
    }
    const winners: number[][] = [[], []];
    for (const [player, lostMatches] of lostMatchesCount) {
        if (lostMatches === 0) winners[0].push(player);
        else if (lostMatches === 1) winners[1].push(player);
    }
    winners[0].sort((a, b) => a - b);
    winners[1].sort((a, b) => a - b);
    return winners;
}
