const VISITED = -1;

function shortestPathBinaryMatrix(grid: number[][]): number {
    const queue = new MyQueue<[number, number]>([[-1, -1]]);
    let dist = 0;
    const last = grid.length - 1;
    while (!queue.isEmpty()) {
        const size = queue.size();
        for (let _ = 0; _ < size; _++) {
            const [i, j] = queue.poll();
            if (i === last && j === last) {
                return dist;
            }
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    const ni = i + di, nj = j + dj;
                    if ((di === 0 && dj == 0) || ni < 0 || ni > last || nj < 0 || nj > last || grid[ni][nj] !== 0) {
                        continue;
                    }
                    grid[ni][nj] = VISITED;
                    queue.add([ni, nj]);
                }
            }
        }
        dist++;
    }
    return -1;
}

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
