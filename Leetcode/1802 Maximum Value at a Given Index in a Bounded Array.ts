function getSum(index: number, value: number, n: number): number {
    let count = 0;

    if (value > index) {
        count += (value + value - index) * (index + 1) / 2;
    } else {
        count += (value + 1) * value / 2 + index - value + 1;
    }

    if (value >= n - index) {
        count += (value + value - n + 1 + index) * (n - index) / 2;
    } else {
        count += (value + 1) * value / 2 + n - index - value;
    }

    return count - value;
}

function maxValue(n: number, index: number, maxSum: number): number {
    let left = 1;
    let right = maxSum;

    while (left < right) {
        const mid = Math.floor((left + right + 1) / 2);
        if (getSum(index, mid, n) <= maxSum) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
