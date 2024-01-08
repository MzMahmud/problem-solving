function findMatrix(nums: number[]): number[][] {
    const frequencies = new Map<number, number>();
    let maxFreq = -1;
    for (const num of nums) {
        const freq = (frequencies.get(num) ?? 0) + 1;
        maxFreq = Math.max(maxFreq, freq);
        frequencies.set(num, freq);
    }
    const matrix: number[][] = Array.from({ length: maxFreq }, (i, _) => []);
    for (const [num, freq] of frequencies) {
        for (let i = 0; i < freq; i++) {
            matrix[i].push(num);
        }
    }
    return matrix;
}
