const moves = [[0, 1], [1, 0], [-1, 0], [0, -1]];

function shortestPathAllKeys(grid: string[]): number {
    const m = grid.length, n = grid[0].length;
    const queue = new MyQueue<number[]>();

    const seen = new Map<number, Set<string>>();
    
    const keySet = new Set<string>();
    const lockSet = new Set<string>();
    let allKeys = 0, startR = -1, startC = -1;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const cell = grid[i][j];
            if (cell >= 'a' && cell <= 'f') {
                allKeys += (1 << (cell.charCodeAt(0) - 'a'.charCodeAt(0)));
                keySet.add(cell);
            }
            if (cell >= 'A' && cell <= 'F') {
                lockSet.add(cell);
            }
            if (cell == '@') {
                startR = i;
                startC = j;
            }
        }
    }

    queue.add([startR, startC, 0, 0]);
    seen.set(0, new Set());
    seen.get(0)?.add(`${startR}, ${startC}`);    
    
    while (!queue.isEmpty()) {
        const [curR, curC, keys, dist] = queue.poll();
        for (const move of moves) {
            const newR = curR + move[0], newC = curC + move[1];
            if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR].charAt(newC) != '#') {
                const cell = grid[newR][newC];
                if (keySet.has(cell)) {
                    if (((1 << (cell.charCodeAt(0) - 'a'.charCodeAt(0))) & keys) != 0) {
                        continue;
                    }
                    const newKeys = (keys | (1 << (cell.charCodeAt(0) - 'a'.charCodeAt(0))));
                    if (newKeys == allKeys) {
                        return dist + 1;
                    }
                    if (!seen.has(newKeys)) seen.set(newKeys, new Set());
                    seen.get(newKeys)?.add(`${newR}, ${newC}`);
                    queue.add([newR, newC, newKeys, dist + 1]);
                }
                if (lockSet.has(cell) && ((keys & (1 << (cell.charCodeAt(0) - 'A'.charCodeAt(0)))) == 0)) {
                    continue;
                } else if (!seen.get(keys)?.has(`${newR}, ${newC}`)) {
                    seen.get(keys)?.add(`${newR}, ${newC}`);
                    queue.add([newR, newC, keys, dist + 1]);
                }
            }
        }
    }
    return -1;
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
