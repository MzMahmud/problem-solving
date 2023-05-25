function new21Game(n: number, k: number, maxPts: number): number {
    if (k === 0) { 
        return 1;
    }
    const prob = new Array<number>(k).fill(0);
    let windowSum = Math.min(maxPts, n - k + 1);
    for (let i = k - 1; i >= 0; i--) {
        prob[i] = windowSum / maxPts;
        const exitIndex = i + maxPts; 
        let exitValue = 0;
        if (exitIndex < k) {
            exitValue = prob[exitIndex];
        } else if (exitIndex <= n) {
            exitValue = 1;
        }
        windowSum += prob[i] - exitValue;
    }
    return prob[0];
}
