class DisjointSet {
    private parents: number[];
    private ranks: number[];
    private n: number;

    constructor(nNodes: number) {
        this.n = nNodes;
        this.parents = new Array<number>(this.n);
        this.ranks = new Array<number>(this.n);
        for (let i = 0; i < this.n; i++) {
            this.parents[i] = i;
            this.ranks[i] = 1;
        }
    }

    find(node: number): number {
        if (this.parents[node] === node) {
            return node;
        }
        return this.parents[node] = this.find(this.parents[node]);
    }

    union(a: number, b: number): boolean {
        const parA = this.find(a), parB = this.find(b);
        if (parA === parB) {
            return false;
        }
        this.n--;
        if (this.ranks[parA] > this.ranks[parB]) {
            this.parents[parB] = parA;
            this.ranks[parA] += this.ranks[parB];
        } else {
            this.parents[parA] = parB;
            this.ranks[parB] += this.ranks[parA];
        }
        return true;
    }

    get size(): number {
        return this.n;
    }
}

function maxNumEdgesToRemove(n: number, edges: number[][]): number {
    const aliceSet = new DisjointSet(n);
    const bobSet = new DisjointSet(n);
    let neededEdges = 0;
    for (const [type, u, v] of edges) {
        if (type === 3) {
            const neededByA = aliceSet.union(u - 1, v - 1);
            const neededByB = bobSet.union(u - 1, v - 1);
            if (neededByA || neededByB) {
                neededEdges++;
            }
        }
    }
    for (const [type, u, v] of edges) {
        if (type === 1 && aliceSet.union(u - 1, v - 1)) {
            neededEdges++;
        }
        if (type === 2 && bobSet.union(u - 1, v - 1)) {
            neededEdges++;
        }
    }
    return aliceSet.size > 1 || bobSet.size > 1 ? -1 : edges.length - neededEdges;
}
