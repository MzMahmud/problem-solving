function maximumSum(nums: number[]): number {
    const digitSumPair = new Map<number, number>();
    let maxSum = -1;
    for (const num of nums) {
        const dSum = digitSum(num);
        const other = digitSumPair.get(dSum);
        if (other == null) {
            digitSumPair.set(dSum, num);
        } else {
            maxSum = Math.max(maxSum, num + other);
            const maxNum = Math.max(other, num);
            digitSumPair.set(dSum, maxNum);
        }
    }
    return maxSum;
}

function digitSum(n: number) {
    let s = 0;
    for (const d of `${n}`) {
        s += Number(d);
    }
    return s;
}
