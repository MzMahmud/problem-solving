function findSmallestSetOfVertices(n: number, edges: number[][]): number[] {
    const inDegree = new Array<number>(n).fill(0);
    for (const [_, v] of edges) {
        inDegree[v]++;
    }
    return inDegree.reduce(
        (minCover, inDeg, node) => {
            if (inDeg === 0) minCover.push(node);
            return minCover;
        },
        new Array<number>()
    );
}
