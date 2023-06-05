function findCircleNum(isConnected: number[][]): number {
    const n = isConnected.length;
    const visited = new Array<boolean>(n).fill(false);
    function dfs(start: number) {
        if (visited[start]) {
            return;
        }
        visited[start] = true;
        for (let neigh = 0; neigh < n; neigh++) {
            if (isConnected[start][neigh]) {
                dfs(neigh);
            }
        }
    }
    let circle = 0;
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            circle++;
            dfs(i);
        }
    }
    return circle;
}
