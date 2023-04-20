const MAX_OCCURRENCE = 2;

function removeDuplicates(nums: number[]): number {
    let i = 0;
    for (const num of nums) {
        if (i < MAX_OCCURRENCE || nums[i - MAX_OCCURRENCE] !== num) {
            nums[i++] = num;
        }
    }
    return i;
}
