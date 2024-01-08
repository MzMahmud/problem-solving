function furthestDistanceFromOrigin(moves: string): number {
    let dist = 0, _count = 0;
    for (const move of moves) {
        if (move === "L") dist--;
        else if (move === "R") dist++;
        else if (move === "_") _count++;
    }
    return Math.abs(dist) + _count;
}
