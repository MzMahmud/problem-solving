// Boyer-Moore Majority Voting Algorithm
// O(n) time, O(1) space
function majorityElement(nums: number[]): number {
    let count = 0, candidate = nums[0];
    for (const n of nums) {
        if (count === 0) candidate = n;
        if (n === candidate) count++;
        else count--;
    }
    return candidate;
    // not needed to check as the problem gurantees that a majority element exists
    count = 0;
    for (const n of nums) {
        if (n === candidate) count++;
    }
    if (count > (nums.length / 2)) return candidate;
    return -1;
}
