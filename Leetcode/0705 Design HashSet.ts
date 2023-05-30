class MyHashSet {
    private containerSize = 1_000_002;
    private container = new Array<boolean>(this.containerSize).fill(false);

    constructor() {}

    add(key: number): void {
        this.container[key] = true;
    }

    remove(key: number): void {
        this.container[key] = false;
    }

    contains(key: number): boolean {
        return this.container[key];
    }
}
