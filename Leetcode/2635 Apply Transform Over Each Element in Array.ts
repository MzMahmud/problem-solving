function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const mapped = [];
    for(let i = 0; i < arr.length; i++) {
        mapped.push(fn(arr[i], i));
    }
    return mapped;
}
