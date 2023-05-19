function calcEquation(equations: string[][], values: number[], queries: string[][]): number[] {
    const adjList = buildAdjList(equations, values);
    const pathProducts = new Map<string, number>();
    function dfs(start: string, end: string) {
        if (start === end)  return;
        const toStartProduct = pathProducts.get(start) ?? 1;
        for (const [neigh, val] of adjList.get(start) ?? []) {
            if (!pathProducts.has(neigh)) {
                pathProducts.set(neigh, toStartProduct * val);
                dfs(neigh, end);
            }
        }
    }
    return queries.map(([start, end]) => {
        pathProducts.clear();
        adjList.has(start) && pathProducts.set(start, 1);
        dfs(start, end);
        return pathProducts.get(end) ?? -1;
    });
}

function buildAdjList(equations: string[][], values: number[]) {
    const adjList = new Map<string, [string, number][]>();
    for (let i = 0; i < equations.length; i++) {
        const [u, v] = equations[i], val = values[i];
        const uList = adjList.get(u) ?? [];
        uList.push([v, val]);
        adjList.set(u, uList);
        const vList = adjList.get(v) ?? [];
        vList.push([u, 1 / val]);
        adjList.set(v, vList);
    }
    return adjList;
}
