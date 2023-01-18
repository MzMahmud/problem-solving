class Solution {
    // O(n) time | O(1) space
    public int maxSubarraySumCircular(int[] nums) {
        int sum = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;
        for (int num : nums) {
            curMax = Math.max(curMax + num, num);
            maxSum = Math.max(maxSum, curMax);
            curMin = Math.min(curMin + num, num);
            minSum = Math.min(minSum, curMin);
            sum += num;
        }
        return maxSum > 0 ? Math.max(maxSum, sum - minSum) : maxSum;
    }

    // O(n) time | O(n) space
    public int maxSubarraySumCircularTwoPass(int[] nums) {
        int n = nums.length;
        int[] reverseMaxSubarraySum = new int[n];
        reverseMaxSubarraySum[n - 1] = nums[n - 1];
        for (int suffixSum = nums[n - 1], i = n - 2; i >= 0; --i) {
            suffixSum += nums[i];
            reverseMaxSubarraySum[i] = Math.max(reverseMaxSubarraySum[i + 1], suffixSum);
        }

        int maxNonCircularSum = nums[0];
        int maxCirularSum = nums[0];
        for (int i = 0, prefixSum = 0, curMax = 0; i < n; ++i) {
            curMax = Math.max(curMax, 0) + nums[i];
            maxNonCircularSum = Math.max(maxNonCircularSum, curMax);
            prefixSum += nums[i];
            if (i + 1 < n) {
                maxCirularSum = Math.max(maxCirularSum, prefixSum + reverseMaxSubarraySum[i + 1]);
            }
        }
        return Math.max(maxNonCircularSum, maxCirularSum);
    }
}
