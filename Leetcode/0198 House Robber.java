class Solution {
    public int rob(int[] nums) {
        return rob(0, nums, new Integer[nums.length]);
    }

    private int rob(int index, int[] nums, Integer[] cache) {
        if (index >= nums.length) {
            return 0;
        }
        if (cache[index] == null) {
            int dontTakeIndex = rob(index + 1, nums, cache);
            int takeIndex = nums[index] + rob(index + 2, nums, cache);
            cache[index] = Math.max(dontTakeIndex, takeIndex);
        }
        return cache[index];
    }
}
