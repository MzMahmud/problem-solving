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
                                
// modular inverse solution O(n)
const modInverse10 = [0, 1, 0, 7, 0, 0, 0, 3, 0, 9];
const exp2Mod10 = [6, 2, 4, 8];

function triangularSum(nums: number[]): number {
    const m = nums.length - 1;
    let mCk = 1, exp2 = 0, exp5 = 0;   
    let lastDigit = 0;
    for (let k = 0; k <= m; k++) {
        if (exp2 === 0 || exp5 === 0) {
            let binom = mCk;
            if (exp2 !== 0) {
                binom = mCk * exp2Mod10[exp2 % 4] % 10;
            } else if (exp5 !== 0) {
                binom = mCk * 5 % 10;
            }
            lastDigit = (lastDigit + binom * nums[k]) % 10;
        }
        if (k == m) {
            continue;
        }
        // mCk *= m - k
        let mul = m - k;
        while (mul % 2 == 0) {
            mul /= 2;
            exp2++;
        }
        while (mul % 5 == 0) {
            mul /= 5;
            exp5++;
        }
        mCk = mCk * mul % 10;

        // mCk /= k + 1
        let div = k + 1;
        while (div % 2 == 0) {
            div /= 2;
            exp2--;
        }
        while (div % 5 == 0) {
            div /= 5;
            exp5--;
        }
        mCk = mCk * modInverse10[div % 10] % 10;
    }
    return lastDigit;
}
