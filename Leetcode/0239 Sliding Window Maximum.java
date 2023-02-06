public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] slidingWindowMax = new int[nums.length - k];
        int slidingWindowIndex = 0;

        Deque<Integer> decreasingDeque = new LinkedList<>();

        for (int i = 0; i < nums.length; ++i) {
            while (!decreasingDeque.isEmpty() && decreasingDeque.peekLast() < nums[i]) {
                decreasingDeque.pollLast();
            }
            decreasingDeque.addLast(i);

            if (i + 1 < k) {
                continue;
            }

            int exitingIndex = i - k;
            if (0 <= exitingIndex && decreasingDeque.peekFirst() == exitingIndex) {
                decreasingDeque.pollFirst();
            }
            slidingWindowMax[slidingWindowIndex++] = nums[decreasingDeque.peekFirst()];
        }
        return slidingWindowMax;
    }
}