function maxSatisfaction(satisfactions: number[]): number {
    satisfactions.sort((a, b) => a - b);
    const n = satisfactions.length;
    const cache = new Array(n);
    for(let i = 0; i < n; i++) {
        cache[i] = new Array(n + 1).fill(Number.MIN_VALUE);
    }
    return maxSatisfactionDp(0, 1, satisfactions, cache);
}

// O(n^2) time DP solution
function maxSatisfactionDp(
    index: number, time: number, 
    satisfactions: number[], cache: number[][]
) {
    if (index == satisfactions.length) {
        return 0;
    }
    if (cache[index][time] != Number.MIN_VALUE) {
        return cache[index][time];
    }
    const ifCooked = satisfactions[index] * time + maxSatisfactionDp(
        index + 1, time + 1, satisfactions, cache
    );
    const ifNotCooked = maxSatisfactionDp(index + 1, time, satisfactions, cache);
    return cache[index][time] = Math.max(ifCooked, ifNotCooked);
}
                         
// O(n log n) time greedy solution
function maxSatisfactionGreedy(satisfactions: number[]) {
    satisfactions.sort((a, b) => a - b);
    let maxLikeTime = 0, suffixSum = 0;
    for (let i = satisfactions.length - 1; i >= 0; i--) {
        suffixSum += satisfactions[i];
        if(suffixSum < 0) {
            break;
        }
        maxLikeTime += suffixSum;
    }
    return maxLikeTime;
}
                         
                      
