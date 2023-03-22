function minScore(n: number, roads: number[][]): number {
    const adjList: [number, number][][] = new Array(n + 1);
    for (let i = 0; i <= n; i++) {
        adjList[i] = [];
    }
    for (const [src, dst, weight] of roads) {
        adjList[src].push([dst, weight]);
        adjList[dst].push([src, weight]);
    }
    let minWeightEdge = Number.MAX_VALUE;
    const visited = new Array(n + 1).fill(false);
    function dfs(start: number) {
        if(visited[start]) {
            return;
        }
        visited[start] = true;
        for(const [child, weight] of adjList[start]) {
            minWeightEdge = Math.min(minWeightEdge, weight);
            dfs(child);
        }
    }
    dfs(1);
    return minWeightEdge;
}
