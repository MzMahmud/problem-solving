type MultidimensionalArray = (MultidimensionalArray | number)[]

function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    yield* inorder(arr);
}

function* inorder(value: number | MultidimensionalArray): Generator<number, void, unknown> {
    if (typeof value === 'number') {
        yield value;
    } else {
        for (const nested of value) {
            yield* inorder(nested);
        }
    }
}

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
