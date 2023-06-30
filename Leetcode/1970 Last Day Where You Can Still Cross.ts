const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];

function canCross(row: number, col: number, cells: number[][], day: number): boolean {
    const grid = Array.from({length: row}, () => new Array<number>(col).fill(0));
    const queue = new MyQueue<[number, number]>();
    for (let i = 0; i < day; i++) {
        grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
    }
    for (let i = 0; i < col; i++) {
        if (grid[0][i] == 0) {
            queue.add([0, i]);
            grid[0][i] = -1;
        }
    }
    while (!queue.isEmpty()) {
        const [r, c] = queue.poll();
        if (r === (row - 1)) {
            return true;
        }
        for (const [dr, dc] of directions) {
            const newRow = r + dr, newCol = c + dc;
            if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == 0) {
                grid[newRow][newCol] = -1;
                queue.add([newRow, newCol]);
            }
        }
    }
    return false;
}

function latestDayToCross(row: number, col: number, cells: number[][]) {
    let left = 1, right = row * col;
    while (left < right) {
        const mid = right - Math.floor((right - left) / 2);
        if (canCross(row, col, cells, mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
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
