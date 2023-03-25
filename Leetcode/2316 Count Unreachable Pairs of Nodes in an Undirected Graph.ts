function countPairs(n: number, edges: number[][]): number {
    const adjList: number[][] = new Array(n);
    for(let i = 0; i < n;i++) {
        adjList[i] = [];
    }
    for(const [src, dst] of edges) {
        adjList[src].push(dst);
        adjList[dst].push(src);
    }
    const visited: boolean[] = new Array(n).fill(false);
    let unreachablePairs = 0, remainingNodes = n;
    for(let node = 0; node < n; node++) {
        if(!visited[node]) {
            const componentSize = dfs(node, adjList, visited);
            unreachablePairs += componentSize * (remainingNodes - componentSize);
            remainingNodes -= componentSize;
        }
    }
    return unreachablePairs;
}

function dfs(start: number, adjList: number[][], visited: boolean[]) {
    visited[start] = true;
    let componentSize = 1;
    for (const neighbour of adjList[start]) {
        if(!visited[neighbour]) {
            componentSize += dfs(neighbour, adjList, visited);
        }
    }
    return componentSize;
}
