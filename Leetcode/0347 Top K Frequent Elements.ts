function topKFrequent(nums: number[], k: number): number[] {
    const freq = new Map<number, number>();
    for (const n of nums) {
        freq.set(n, 1 + (freq.get(n) ?? 0));
    }
    const topElems = new MyPriorityQueue<[number, number]>([], (a, b) => a[0] - b[0]);
    for (const [e, f] of freq.entries()) {
        if (topElems.size() < k || f >= topElems.peek()[0]) {
            topElems.add([f, e]);
            if (topElems.size() > k) {
                topElems.poll();
            }
        }
    }
    const elems: number[] = [];
    while (!topElems.isEmpty()) {
        elems.push(topElems.poll()[1]);
    }
    return elems;
}

type CompareFn<T> = (a: T, b: T) => number;

class MyPriorityQueue<T> {
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

    private parent(index: number) {
        return (index - 1) >> 1;
    }

    private left(index: number) {
        return (index << 1) + 1;
    }

    private right(index: number) {
        return (index << 1) + 2;
    }

    private swap(i: number, j: number) {
        const temp = this.heap[i];
        this.heap[i] = this.heap[j];
        this.heap[j] = temp;
    }

    private heapifyUp(start: number) {
        while (start > 0 && this.compareFn(this.heap[start], this.heap[this.parent(start)]) < 0) {
            const parent = this.parent(start);
            this.swap(start, parent);
            start = parent;
        }
    }

    private heapifyDown(start: number) {
        const size = this.size();
        let minIndex = start, left = this.left(start), right = this.right(start);
        if (left < size && this.compareFn(this.heap[left], this.heap[minIndex]) < 0) {
            minIndex = left;
        }
        if (right < size && this.compareFn(this.heap[right], this.heap[minIndex]) < 0) {
            minIndex = right;
        }
        if (minIndex !== start) {
            this.swap(start, minIndex);
            this.heapifyDown(minIndex);
        }
    }

    private buildHeap() {
        let start = (this.size() >> 1) - 1;
        for (; start >= 0; start--) {
            this.heapifyDown(start);
        }
    }
}
