function differenceOfSum(nums: number[]): number {
    let elemSum = 0, digitSum = 0;
    for (const num of nums) {
        elemSum += num;
        digitSum += getDigitSum(num);
    }
    return Math.abs(elemSum - digitSum);
}

function getDigitSum(n: number) {
    let digitSum = 0;
    while (n > 0) {
        digitSum += n % 10;
        n = Math.floor(n / 10);
    }
    return digitSum;
}
