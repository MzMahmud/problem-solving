class PeekingIterator {
    private _next: number;
    private _hasNext: boolean;

    constructor(private iterator: Iterator) {
        this._hasNext = this.iterator.hasNext();
        this._next = iterator.next();
    }

    peek(): number {
        return this._next;
    }

    next(): number {
        const _next = this._next;
        this._hasNext = this.iterator.hasNext();
        this._next = this.iterator.next();
        return _next;
    }

    hasNext(): boolean {
        return this._hasNext;
    }
}
