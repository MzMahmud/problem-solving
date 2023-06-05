function numOfMinutes(n: number, headId: number, manager: number[], informTime: number[]): number {
    const adjList = new Array<number[]>(n);
    for (let i = 0; i < n; i++) {
        adjList[i] = [];
    }
    for (let i = 0; i < n; i++) {
        if (manager[i] !== -1) {
            adjList[manager[i]].push(i);
        }
    }
    let time = -Infinity;
    function dfs(start: number, t: number) {
        time = Math.max(time, t);
        for (const neigh of adjList[start]) {
            dfs(neigh, t + informTime[start]);
        }
        return time;
    }
    return dfs(headId, 0);
}
