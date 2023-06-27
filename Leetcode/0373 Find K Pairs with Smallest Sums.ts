function kSmallestPairs(nums1: number[], nums2: number[], k: number): number[][] {
    const m = nums1.length, n = nums2.length;
    const pairs = new Array<number[]>();
    const visited = new Set<string>();
    const minHeap = new MyPriorityQueue<[number, number, number]>([], (a, b) => a[0] - b[0]);
    minHeap.add([nums1[0] + nums2[0], 0, 0]);
    visited.add(`0,0`);
    while (k-- > 0 && !minHeap.isEmpty()) {
        const [_, i, j] = minHeap.poll();
        pairs.push([nums1[i], nums2[j]]);
        if (i + 1 < m && !visited.has(`${i + 1}, ${j}`)) {
            minHeap.add([nums1[i + 1] + nums2[j], i + 1, j]);
            visited.add(`${i + 1}, ${j}`);
        }
        if (j + 1 < n && !visited.has(`${i}, ${j + 1}`)) {
            minHeap.add([nums1[i] + nums2[j + 1], i, j + 1]);
            visited.add(`${i}, ${j + 1}`);
        }
    }
    return pairs;
}


// PriorityQueue Implementation
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
