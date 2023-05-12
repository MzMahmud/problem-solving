function mostPoints(questions: number[][]): number {
    const cache = new Array<number>(questions.length).fill(-1);
    function dfs(i: number): number {
        if (i >= questions.length) {
            return 0;
        }
        if (cache[i] === -1) {
            cache[i] = Math.max(
                dfs(i + 1), 
                questions[i][0] + dfs(i + questions[i][1] + 1)
            );
        }
        return cache[i];
    }
    return dfs(0);
}
