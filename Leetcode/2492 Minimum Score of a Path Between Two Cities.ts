function minScore(n: number, roads: number[][]): number {
    const adjList: Map<number, [number, number][]> = new Map();
    for (const [src, dst, weight] of roads) {
        if(!adjList.has(src)) {
            adjList.set(src, []);
        }
        if(!adjList.has(dst)) {
            adjList.set(dst, []);
        }
        adjList.get(src).push([dst, weight]);
        adjList.get(dst).push([src, weight]);
    }
    let minWeightEdge = Number.MAX_VALUE;
    const visited = new Set<number>();
    function dfs(start: number) {
        if(visited.has(start)) {
            return;
        }
        visited.add(start);
        for(const [child, weight] of adjList.get(start) ?? []) {
            minWeightEdge = Math.min(minWeightEdge, weight);
            dfs(child);
        }
    }
    dfs(1);
    return minWeightEdge;
}
