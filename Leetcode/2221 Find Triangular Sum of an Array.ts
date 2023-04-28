// binomial coefficient solution, O(n^2) time
// can be improved to O(n) time by using moduler inverse 
function triangularSum(nums: number[]): number {
    const n = nums.length;
    const binom = getBinom(n - 1, 10);
    let lastDigit = 0;
    for (let i = 0; i < n; i++) {
        lastDigit = (lastDigit + binom[n - 1][i] * nums[i]) % 10;
    }
    return lastDigit;
}

function getBinom(N: number, mod: number) {
    const binom = new Array<number[]>(N + 1);
    for (let n = 0; n <= N; n++) {
        binom[n] = new Array<number>(n + 1).fill(0);
    }
    for (let n = 0; n <= N; n++) {
        for (let r = 0; r <= n; r++) {
            if (r === 0 || n === r) {
                binom[n][r] = 1 % mod;
            } else if (r > (n / 2)) {
                binom[n][r] = binom[n][n - r];
            } else {
                binom[n][r] = (binom[n - 1][r] + binom[n - 1][r - 1]) % mod;
            }
        }
    }
    return binom;
}

// simple simulation solution O(n^2) time
function triangularSum(nums: number[]): number {
    for (let len = nums.length; len > 1; len--) {
        for (let i = 1; i < len; i++) {
            nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
        }
    }
    return nums[0];
}
