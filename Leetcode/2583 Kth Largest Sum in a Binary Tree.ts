function kthLargestLevelSum(root: TreeNode, k: number): number {
    let q: TreeNode[] = [root];
    const topK = new MyPriorityQueue<number>();
    while (q.length > 0) {
        const newQ: TreeNode[] = [];
        let levelSum = 0;
        for (const node of q) {
            levelSum += node.val;
            if (node.left) newQ.push(node.left);
            if (node.right) newQ.push(node.right);
        }
        topK.add(levelSum);
        if (topK.size() > k) topK.poll();
        q = newQ;
    }
    if (k > topK.size()) return -1;
    return topK.peek();
}

type CompareFn<T> = (a: T, b: T) => number;

class MyPriorityQueue<T> implements Iterable<T> {
    private heap: T[] = [];
    private compareFn: CompareFn<T> = (a, b) => a === b ? 0 : (a < b ? -1 : 1);

    constructor({ data, compareFn }: { data?: Iterable<T>, compareFn?: CompareFn<T> } = {}) {
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

    *[Symbol.iterator]() {
        const heap = [...this.heap].sort(this.compareFn);
        for (const t of heap) yield t;
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
