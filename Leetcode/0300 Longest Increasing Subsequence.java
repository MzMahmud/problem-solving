class Solution {
    // classic DP O(n^2) time, O(n) space
    // formulation
    // lis[i] = length of lis ending at index i
    public int lengthOfLIS(int[] nums) {
        int[] lis = new int[nums.length];
        int maxLis = 0;
        for (int i = 0; i < lis.length; ++i) {
            lis[i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    lis[i] = Math.max(lis[i], 1 + lis[j]);
                }
            }
            maxLis = Math.max(maxLis, lis[i]);
        }
        return maxLis;
    }

    // find and update max element of a length with binary search
    // O(n log n) time, O(n) space
    public int lengthOfLIS(int[] nums) {
        List<Integer> maxElementByLength = new ArrayList<>();
        for (var num : nums) {
            boolean emptyOrHigherThanMaxSize = (
                maxElementByLength.isEmpty()
                || maxElementByLength.get(maxElementByLength.size() - 1) < num
            );
            if (emptyOrHigherThanMaxSize) {
                maxElementByLength.add(num);
                continue;
            }
            int lowerBoundIndex = findLowerBoundIndex(maxElementByLength, num);
            maxElementByLength.set(lowerBoundIndex, num);
        }
        return maxElementByLength.size();
    }

    private int findLowerBoundIndex(List<Integer> sortedList, int value) {
        int lo = 0, hi = sortedList.size() - 1;
        int lowerBoundIndex = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (sortedList.get(mid) >= value) {
                lowerBoundIndex = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lowerBoundIndex;
    }
}