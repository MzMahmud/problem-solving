class DisjointSet {
    private parent: number[];
    private rank: number[];

    constructor(n: number) {
        this.parent = new Array<number>();
        this.rank = new Array<number>();
        for (let i = 0; i < n; i++) {
            this.parent[i] = i;
            this.rank[i] = 1;
        }
    }

    find(a: number): number {
        if (this.parent[a] === a) {
            return a;
        }
        return this.parent[a] = this.find(this.parent[a]);
    }

    union(a: number, b: number): boolean {
        a = this.find(a), b = this.find(b);
        if (a === b) {
            return false;
        }
        if (this.rank[a] > this.rank[b]) {
            this.parent[b] = a;
            this.rank[a] += this.rank[b];
        } else {
            this.parent[a] = b;
            this.rank[b] += this.rank[a];
        }
        return true;
    }
}

function findRedundantConnection(edges: number[][]): number[] {
    const disjointSet = new DisjointSet(edges.length);
    for (const edge of edges) {
        if (!disjointSet.union(edge[0], edge[1])) {
            return edge;
        }
    }
    return [];
}
