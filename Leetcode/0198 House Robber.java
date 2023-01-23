class Solution {
    // optimized DP Solution
    public int rob(int[] nums) {
        int lootN = 0, lootN_2 = 0, lootN_1 = 0;
        for (int num : nums) {
            lootN = Math.max(lootN_1, num + lootN_2);
            lootN_2 = lootN_1;
            lootN_1 = lootN;
        }
        return lootN;
    }

    public int robDpSolution(int[] nums) {
        return robDpSolution(0, nums, new Integer[nums.length]);
    }

    private int robDpSolution(int index, int[] nums, Integer[] cache) {
        if (index >= nums.length) {
            return 0;
        }
        if (cache[index] == null) {
            int dontTakeIndex = robDpSolution(index + 1, nums, cache);
            int takeIndex = nums[index] + robDpSolution(index + 2, nums, cache);
            cache[index] = Math.max(dontTakeIndex, takeIndex);
        }
        return cache[index];
    }
}
