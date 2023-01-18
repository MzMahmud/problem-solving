class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int[] reverseMaxSubarraySum = new int[n];
        reverseMaxSubarraySum[n - 1] = nums[n - 1];
        for (int suffixSum = nums[n - 1], i = n - 2; i >= 0; --i) {
            suffixSum += nums[i];
            reverseMaxSubarraySum[i] = Math.max(reverseMaxSubarraySum[i + 1], suffixSum);
        }

        int maxSum = nums[0];
        int specialSum = nums[0];
        for (int i = 0, prefixSum = 0, curMax = 0; i < n; ++i) {
            curMax = Math.max(curMax, 0) + nums[i];
            maxSum = Math.max(maxSum, curMax);
            prefixSum += nums[i];
            if (i + 1 < n) {
                specialSum = Math.max(specialSum, prefixSum + reverseMaxSubarraySum[i + 1]);
            }
        }
        return Math.max(maxSum, specialSum);  
    }
}
