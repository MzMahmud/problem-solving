function countCompleteComponents(n: number, edges: number[][]): number {
    const adjList = new Array<number[]>(n);
    for (let i = 0; i < n; i++) adjList[i] = new Array<number>();
    for (const [u, v] of edges) {
        adjList[u].push(v);
        adjList[v].push(u);
    }
    const visited = new Array<boolean>(n).fill(false);
    let nV = 0, nE = 0, nComplete = 0;
    function dfs(start: number) {
        if (visited[start]) return;
        visited[start] = true;
        nV++;
        nE += adjList[start].length;
        adjList[start].forEach(dfs);
    }
    for (let node  = 0; node < n; node++) {
        if (visited[node]) continue;
        nV = 0, nE = 0;
        dfs(node);
        if (isComplete(nV, nE)) nComplete++;
    }
    return nComplete;
}

function isComplete(nV: number, nE: number) {
    return (nV * (nV - 1)) === nE;
}
