function maxLevelSum(root: TreeNode | null): number {
    const queue = new MyQueue<TreeNode>();
    if (root !== null) queue.add(root);
    let level = 1, maxLevel = 1, maxSum = -Infinity;
    while(!queue.isEmpty()) {
        const size = queue.size();
        let sum = 0;
        for (let i = 0; i < size; i++) {
            const node = queue.poll();
            sum += node.val;
            if (node.left !== null) queue.add(node.left);
            if (node.right !== null) queue.add(node.right);
        }
        if (sum > maxSum) {
            maxLevel = level;
            maxSum = sum;
        }
        level++;
    }
    return maxLevel;
}

// Queue Implementation
class MyListNode<T> {
    data: T;
    next: MyListNode<T> | null;

    constructor(data: T, next?: MyListNode<T> | null) {
        this.data = data;
        this.next = next === undefined ? null : next;
    }
}

class MyQueue<T> implements Iterable<T> {
    private head: MyListNode<T> | null = null;
    private tail: MyListNode<T> | null = null;
    private length: number = 0;

    constructor(array: T[] = []) {
        for (const data of array) {
            this.add(data);
        }
    }

    size(): number {
        return this.length;
    }

    isEmpty(): boolean {
        return this.length === 0;
    }

    peek(): T {
        if (this.head === null) throw new Error("queue is empty");
        return this.head.data;
    }

    add(value: T) {
        const newNode = new MyListNode<T>(value);
        if (this.tail === null) {
            this.head = this.tail = newNode;
        } else {
            this.tail.next = newNode;
        }
        this.tail = newNode;
        this.length++;
    }

    poll(): T {
        if (this.head === null) throw new Error("queue is empty");
        const front = this.head.data;
        this.head = this.head.next;
        this.length--;
        if (this.length === 0) {
            this.tail = null;
        }
        return front;
    }

    [Symbol.iterator](): Iterator<T> {
        let head = this.head;
        return {
            next: (): IteratorResult<T> => {
                if (head === null) return { value: undefined, done: true };
                const value = head.data;
                head = head.next;
                return { value: value, done: false };
            }
        }
    }
}
