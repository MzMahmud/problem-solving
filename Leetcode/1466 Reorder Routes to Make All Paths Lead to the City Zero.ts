const [FORWARD, BACKWARD] = [1, 0];

function minReorder(n: number, connections: number[][]): number {
    const adjList: [number, number][][] = new Array(n);
    for (let i = 0; i < n; i++) {
        adjList[i] = [];
    }
    for (const [src, dst] of connections) {
        adjList[src].push([dst, FORWARD]);
        adjList[dst].push([src, BACKWARD]);
    }
    let nParentToChildEdges = 0;
    const dfs = (root: number, parent: number) => {
        for (const [child, direction] of adjList[root]) {
            if (child !== parent) {    
                nParentToChildEdges += direction;
                dfs(child, root);
            }
        }
    }
    dfs(0, -1);
    return nParentToChildEdges;
}
