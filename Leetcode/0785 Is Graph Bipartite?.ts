type NodeColor = 'B' | 'W' | null;

function isBipartite(graph: number[][]): boolean {
    const colors = new Array<NodeColor>(graph.length).fill(null);
    function dfs(node: number, expected: NodeColor): boolean {
        if (colors[node] !== null) {
            return colors[node] === expected;
        }
        colors[node] = expected;
        const neighColor = colors[node] === 'B' ? 'W' : 'B'; 
        for (const neigh of graph[node]) {
            if (!dfs(neigh, neighColor)) {
                return false;
            }
        }
        return true;
    }
    for (let node = 0; node < graph.length; node++) {
        if (colors[node] === null && !dfs(node, 'B')) {
            return false;
        }
    }
    return true;
}
