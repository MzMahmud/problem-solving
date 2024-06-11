function relativeSortArray(arr1: number[], arr2: number[]): number[] {
    const indexByValue = new Map(arr2.map((v, i) => [v, i]));
    const compareFn = (a: number, b: number) => {
        const _a = indexByValue.get(a);
        const _b = indexByValue.get(b);
        if (_a == null && _b == null) return a - b;
        if (_a == null) return 1;
        if (_b == null) return -1;
        return _a - _b;
    }
    return arr1.sort(compareFn);
}
