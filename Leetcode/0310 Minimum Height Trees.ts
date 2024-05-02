function findMinHeightTrees(n: number, edges: number[][]): number[] {
    if (n == 1) return [0];
    const adjList = Array.from({ length: n }, (): number[] => []);
    const deg = Array.from(adjList, () => 0);
    for (const [u, v] of edges) {
        adjList[u].push(v);
        adjList[v].push(u);
        deg[u]++, deg[v]++;
    }
    let leaves: number[] = [];
    deg.forEach((d, i) => d === 1 && leaves.push(i));
    while (n > 2) {
        n -= leaves.length;
        const newLeaves: number[] = [];
        for (const node of leaves) {
            for (const next of adjList[node]) {
                deg[next]--;
                deg[next] === 1 && newLeaves.push(next);
            }
        }
        leaves = newLeaves;
    }
    return leaves;
}
