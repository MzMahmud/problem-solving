function arraySign(nums: number[]): number {
    let sign = 1;
    for (const num of nums) {
        if (num === 0) {
            return 0;
        }
        if (num < 0) {
            sign *= -1;
        }
    }
    return sign;
}

// functional solution
function arraySign(nums: number[]): number {
    return nums.reduce((sign, num) => sign * sigNum(num), 1);
}

function sigNum(n: number) {
    return n === 0? 0 : (n < 0? -1 : 1);
}
