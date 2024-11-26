function findChampion(n: number, edges: number[][]): number {
    const inDegrees: number[] = Array.from({ length: n }, () => 0);
    for (const [_, v] of edges) {
        inDegrees[v]++;
    }
    let champion = -1;
    for (let u = 0; u < n; u++) {
        if (inDegrees[u] === 0) {
            if (champion === -1) {
                champion = u;
            } else {
                champion = -1;
                break;
            }
        }
    }
    return champion;
}
