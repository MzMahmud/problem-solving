function combinationSum2(candidates: number[], target: number): number[][] {
    const numCounts = getNumberCounts(candidates);
    const collection: number[][] = [];
    function combination(list: number[], sum: number, index: number) {
        if (sum === target) {
            collection.push([...list]);
            return;
        }
        if (index >= numCounts.length) return;
        const [num, count] = numCounts[index];
        for (let k = 0; k <= count; k++) {
            const nextSum = sum + k * num;
            if (nextSum > target) continue;
            for (let i = 0; i < k; i++) list.push(num);
            combination(list, nextSum, index + 1);
            for (let i = 0; i < k; i++) list.pop();
        }
    }
    combination([], 0, 0);
    return collection;
}

function getNumberCounts(nums: number[]) {
    const counts = new Map<number, number>();
    for (const n of nums) {
        const count = counts.get(n) ?? 0;
        counts.set(n, count + 1);
    }
    return [...counts.entries()];
}
