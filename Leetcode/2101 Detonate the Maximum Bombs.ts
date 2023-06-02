function maximumDetonation(bombs: number[][]): number {
    const n = bombs.length;
    const adjList = new Array<number[]>(n);
    for (let i = 0; i < n; i++) {
        adjList[i] = new Array<number>();
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i !== j && isInRange(bombs[i], bombs[j])) {
                adjList[i].push(j);
            }
        }
    }
    function dfs(start: number, visited: boolean[]): number {
        if (visited[start]) {
            return 0;
        }
        visited[start] = true;
        let nNodes = 1;
        for (let neigh of adjList[start]) {
            nNodes += dfs(neigh, visited);
        }
        return nNodes;
    }
    let maxBombs = 0;
    for (let i = 0; i < n; i++) {
        maxBombs = Math.max(maxBombs, dfs(i, new Array<boolean>(n).fill(false)));
    }
    return maxBombs;
}

function isInRange(bomb1: number[], bomb2: number[]) {
    const delX = bomb1[0] - bomb2[0], delY = bomb1[1] - bomb2[1];
    const distSq = delX * delX + delY * delY;
    return distSq <= (bomb1[2] * bomb1[2]);
}
