const [FORWARD, BACKWARD] = [1, -1];

function minReorder(n: number, connections: number[][]): number {
    const adjListWithDirection: [number, number][][] = new Array(n);
    for (let i = 0; i < n; i++) {
        adjListWithDirection[i] = [];
    }
    for (const [src, dst] of connections) {
        adjListWithDirection[src].push([dst, FORWARD]);
        adjListWithDirection[dst].push([src, BACKWARD]);
    }
    let nParentToChildEdges = 0;
    const dfs = (root: number, parent: number) => {
        for (const [child, edgeDirection] of adjListWithDirection[root]) {
            if (child === parent) {
                continue;
            }
            if (edgeDirection == FORWARD) {
                nParentToChildEdges++;
            }
            dfs(child, root);
        }
    }
    dfs(0, -1);
    return nParentToChildEdges;
}
