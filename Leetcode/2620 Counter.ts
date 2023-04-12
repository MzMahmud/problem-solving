function createCounter(n: number): () => number {
    let value = n - 1;
    return function() {
        value++;
        return value;
    }
}


/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
