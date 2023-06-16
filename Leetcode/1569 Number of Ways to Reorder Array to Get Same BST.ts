const MOD = 1_000_000_007n;

function numOfWays(nums: number[]): number {
    const m = nums.length;
    const nCr = new Array<bigint[]>(m);
    for (let n = 0; n < m; n++) {
        nCr[n] = new Array<bigint>(n + 1);
        for (let r = 0; r <= n; r++) {
            if (r === 0 || r === n) nCr[n][r] = 1n;
            else nCr[n][r] = (nCr[n - 1][r] + nCr[n - 1][r - 1]) % MOD;
        }
    }
    function ways(nums: number[]): bigint {
        const n = nums.length;
        if (n < 3) {
            return 1n;
        }
        const left: number[] = [], right: number[] = [];
        for (let i = 1; i < n; i++) {
            if (nums[i] < nums[0]) left.push(nums[i]);
            else if (nums[i] > nums[0]) right.push(nums[i]);
        }
        return (((ways(left) * ways(right)) % MOD) * nCr[n - 1][left.length]) % MOD;
    }
    return Number((ways(nums) - 1n) % MOD);
}
