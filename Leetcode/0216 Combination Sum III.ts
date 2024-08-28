function combinationSum3(k: number, n: number): number[][] {
    const curr: number[] = [];
    const all: number[][] = [];
    function backtrack(i: number, k: number, n: number) {
        if (n == 0 && k == 0) {
            all.push([...curr]);
            return;
        }
        if (i > 9) return;
        backtrack(i + 1, k, n);
        curr.push(i);
        backtrack(i + 1, k - 1, n - i);
        curr.pop();
    }
    backtrack(1, k, n);
    return all;
}
