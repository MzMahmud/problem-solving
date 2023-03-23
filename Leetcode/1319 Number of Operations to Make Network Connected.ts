function makeConnected(n: number, connections: number[][]): number {
    if (connections.length < (n - 1)) {
        return -1;
    }
    const adjList = getAdjList(n, connections);
    const visited: boolean[] = new Array(n).fill(false);
    let connectedComponents = 0;
    for (let start = 0; start < n; start++) {
        if (!visited[start]) {
            dfs(start, adjList, visited);
            connectedComponents++;
        }
    }
    return connectedComponents - 1;
}

function getAdjList(n: number, edges: number[][]) {
    const adjList: number[][] = new Array(n);
    for (let i = 0; i < n; i++) {
        adjList[i] = [];
    }
    for (const [src, dst] of edges) {
        adjList[src].push(dst);
        adjList[dst].push(src);
    }
    return adjList;
}

function dfs(start: number, adjList: number[][], visited: boolean[]) {
    if (visited[start]) {
        return;
    }
    visited[start] = true;
    for (const child of adjList[start]) {
        dfs(child, adjList, visited);
    }
}
