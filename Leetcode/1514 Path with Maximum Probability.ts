function maxProbability(n: number, edges: number[][], succProb: number[], start: number, end: number): number {
    const adjList = Array.from({length: n}, () => new Array<[number, number]>());
    for (let i = 0; i < edges.length; i++) {
        const [u, v] = edges[i], p = succProb[i];
        adjList[u].push([v, p]);
        adjList[v].push([u, p]);
    }
    const maxProb = new Array<number>(n).fill(0);
    maxProb[start] = 1;
    const pq = new MyPriorityQueue<[number, number]>([[start, 1.0]], (a, b) => b[1] - a[1]);
    while (!pq.isEmpty()) {
        const [curNode, curProb] = pq.poll();
        if (curNode == end) {
            return curProb;
        }
        for (const [neigh, pathProb] of adjList[curNode]) {
            const prob = curProb * pathProb;
            if (prob > maxProb[neigh]) {
                maxProb[neigh] = prob;
                pq.add([neigh, prob]);
            }
        }
    }
    return 0;
}


// PriorityQueue Implmentation
type CompareFn<T> = (a: T, b: T) => number;

class MyPriorityQueue<T> implements Iterable<T> {
    private heap: T[] = [];
    private compareFn: CompareFn<T> = (a, b) => a === b ? 0 : (a < b ? -1 : 1);

    constructor(data?: Iterable<T>, compareFn?: CompareFn<T>) {
        if (data != null) this.heap = [...data];
        if (compareFn != null) this.compareFn = compareFn;
        this.buildHeap();
    }

    size() {
        return this.heap.length;
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    add(value: T) {
        this.heap.push(value);
        this.heapifyUp(this.heap.length - 1);
    }

    peek() {
        if (this.isEmpty()) throw new Error('PriorityQueue is empty');
        return this.heap[0];
    }

    poll() {
        if (this.isEmpty()) throw new Error('PriorityQueue is empty');
        const top = this.heap[0];
        this.swap(0, this.heap.length - 1);
        this.heap.pop();
        this.heapifyDown(0);
        return top;
    }

    [Symbol.iterator](): Iterator<T> {
        const heap = [...this.heap].sort(this.compareFn);
        let index = 0;
        return {
            next: (): IteratorResult<T> => {
                if (index === heap.length) {
                    return { value: undefined, done: true };
                }
                return { value: heap[index++], done: false };
            }
        };
    }

    private parent(index: number) {
        return (index - 1) >> 1;
    }

    private left(index: number) {
        return (index << 1) + 1;
    }

    private right(index: number) {
        return (index << 1) + 2;
    }

    private hasMorePriority(i: number, j: number): boolean {
        return this.compareFn(this.heap[i], this.heap[j]) < 0;
    }

    private swap(i: number, j: number) {
        const temp = this.heap[i];
        this.heap[i] = this.heap[j];
        this.heap[j] = temp;
    }

    private heapifyUp(start: number) {
        let parent: number;
        while (start > 0 && this.hasMorePriority(start, parent = this.parent(start))) {
            this.swap(start, parent);
            start = parent;
        }
    }

    private highPriorityIndex(start: number) {
        const size = this.size(), left = this.left(start), right = this.right(start);
        let highPriority = start;
        if (left < size && this.hasMorePriority(left, highPriority)) {
            highPriority = left;
        }
        if (right < size && this.hasMorePriority(right, highPriority)) {
            highPriority = right;
        }
        return highPriority;
    }

    private heapifyDown(start: number) {
        let highPriority: number;
        while (start != (highPriority = this.highPriorityIndex(start))) {
            this.swap(start, highPriority);
            start = highPriority;
        }
    }

    private buildHeap() {
        for (let start = this.parent(this.size() - 1); start >= 0; start--) {
            this.heapifyDown(start);
        }
    }
}
