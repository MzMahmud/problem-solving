declare global {
    interface Array<T> {
        last(): T | -1;
    }
}

Array.prototype.last = function() {
    const lastElem = this.at(this.length - 1);
    return lastElem === undefined? -1: lastElem;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
