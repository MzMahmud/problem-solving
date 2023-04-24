function countPairs(root: TreeNode | null, distance: number): number {
    let nGoodPairs = 0;
    function dfs (root: TreeNode | null): [number, number][] {
        if (root === null) {
            return []; 
        }
        if (root.left === null && root.right === null) {
            return [[0 , 1]];
        }
        const left = dfs(root.left), right = dfs(root.right);
        for(let i = 0; i < left.length; i++) {
            for (let j = 0; j < right.length; j++) {
                const dist = left[i][0] + right[j][0] + 2;
                if (dist <= distance) {
                    nGoodPairs += left[i][1] * right[j][1];
                }
            }
        }
        const nLeafsByDist = new Map<number, number>();
        for(let i = 0; i < left.length; i++) {
            const dist = 1 + left[i][0];
            if (dist <= distance) {
                nLeafsByDist.set(dist, left[i][1]);
            }
        }
        for(let j = 0; j < right.length; j++) {
            const dist = 1 + right[j][0];
            if (dist <= distance) {
                const count = nLeafsByDist.get(dist) ?? 0;
                nLeafsByDist.set(dist, count + right[j][1]);
            }
        }
        return [...nLeafsByDist.entries()];
    }
    dfs(root);
    return nGoodPairs;
}
