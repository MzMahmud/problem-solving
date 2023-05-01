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

    isInSameSet(a: number, b: number): boolean {
        return this.find(a) === this.find(b);
    }

    get size(): number {
        return this.n;
    }
}

function distanceLimitedPathsExist(n: number, edgeList: number[][], queries: number[][]): boolean[] {
    for (let i = 0; i < queries.length; i++) {
        queries[i].push(i);
    }
    queries.sort((a, b) => a[2] - b[2]);
    edgeList.sort((a, b) => a[2] - b[2]);
    let edgeIndex = 0;
    const disjointSet = new DisjointSet(n);
    const pathExists = new Array<boolean>(queries.length);
    for (const [u, v, limit, index] of queries) {
        while (edgeIndex < edgeList.length && edgeList[edgeIndex][2] < limit) {
            disjointSet.union(edgeList[edgeIndex][0], edgeList[edgeIndex][1]);
            edgeIndex++;
        }
        pathExists[index] = disjointSet.isInSameSet(u, v);
    }
    return pathExists;
}
