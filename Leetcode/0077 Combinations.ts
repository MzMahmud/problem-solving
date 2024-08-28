function combine(n: number, k: number) {
    const combinations: number[][] = [];
    function choose(n: number, k: number, combination: number[]) {
        if (n < k) return;
        if (k == 0) {
            combinations.push([...combination]);
            return;
        }
        combination.push(n);
        choose(n - 1, k - 1, combination);
        combination.pop();
        choose(n - 1, k, combination);
    }
    choose(n, k, []);
    return combinations;
}
